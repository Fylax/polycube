/*
 * Copyright 2017 The Polycube Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <algorithm>
#include <thread>

#include <errno.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "config.h"
#include "polycube/services/json.hpp"
#include "rest_server.h"
#include "utils.h"
#include "version.h"

#include <spdlog/spdlog.h>

#define REQUIRED_POLYCUBED_KERNEL ("4.14.0")

using json = nlohmann::json;
using namespace Pistache;
using namespace polycube::polycubed;

using namespace configuration;

static std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> file;
static std::shared_ptr<spdlog::sinks::stdout_sink_mt> console;
static spdlog::sinks_init_list sinks;
std::shared_ptr<spdlog::logger> logger;

// create core instance
PolycubedCore *core;
RestServer *restserver;

void shutdown() {
  static bool done = false;
  if (done)
    return;
  restserver->shutdown();
  logger->debug("rest was shutdown");
  delete core;
  logger->info("polycubed is shutting down. Bye!");
  done = true;
}

void shutdown_handler(int s) {
  logger->info("Caught signal {0}", s);
  shutdown();
  exit(0);
}

void initlogger() {
  spdlog::drop("polycubed");
  file = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
      config.getLogFile(), 1048576 * 5, 3);
  console = std::make_shared<spdlog::sinks::stdout_sink_mt>();
  sinks = {file, console};
  logger = std::make_shared<spdlog::logger>("polycubed", sinks);
  logger->flush_on(spdlog::level::trace);
}

void daemonize(void) {
  pid_t pid;

  /* Fork off the parent process */
  pid = fork();

  /* An error occurred */
  if (pid < 0) {
    logger->error("fork() error");
    exit(EXIT_FAILURE);
  }

  /* Success: Let the parent terminate */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  /* On success: The child process becomes session leader */
  if (setsid() < 0) {
    logger->error("setsid() error");
    exit(EXIT_FAILURE);
  }

  /* Catch, ignore and handle signals */
  // TODO: Implement a working signal handler */
  signal(SIGCHLD, SIG_IGN);
  signal(SIGHUP, SIG_IGN);

  /* Fork off for the second time*/
  pid = fork();

  /* An error occurred */
  if (pid < 0) {
    logger->error("fork() error");
    exit(EXIT_FAILURE);
  }

  /* Success: Let the parent terminate */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  /* Set new file permissions */
  umask(0644);

  /* Change the working directory to the root directory */
  /* or another appropriated directory */
  chdir("/");

  /* Close all open file descriptors */
  for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
    close(x);
  }
}

// this function is implemented in the load_services.cpp file
// that is automatically generated by CMake
void load_services(PolycubedCore &core);

int main(int argc, char *argv[]) {
  // init logger ASAP, to print early error messages
  console = std::make_shared<spdlog::sinks::stdout_sink_mt>();
  sinks = {console};
  logger = std::make_shared<spdlog::logger>("polycubed", sinks);
  logger->flush_on(spdlog::level::trace);
  spdlog::register_logger(logger);

  try {
    if (!config.load(argc, argv)) {
      exit(EXIT_SUCCESS);
    }
  } catch (const std::exception &e) {
    logger->critical("Error loading config: {}", e.what());
    exit(EXIT_FAILURE);
  }

  initlogger();
  spdlog::register_logger(logger);
  logger->set_level(config.getLogLevel());

  if (getuid()) {
    logger->critical("please run polycubed as root");
    exit(EXIT_FAILURE);
  }

  config.dump();

  logger->info("polycubed starting...");
  logger->info("version {}", VERSION);

  if (!utils::check_kernel_version(REQUIRED_POLYCUBED_KERNEL)) {
    logger->error("kernel {0} is required for polycubed",
                  REQUIRED_POLYCUBED_KERNEL);
    exit(EXIT_FAILURE);
  }

  if (config.getDaemon()) {
    logger->info("running as daemon");
    daemonize();
    spdlog::drop("polycubed");
    // in daemon mode log only to the file
    file = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        config.getLogFile(), 1048576 * 5, 3);
    logger = std::make_shared<spdlog::logger>("polycubed", file);
    spdlog::register_logger(logger);
  }

  /*
   * check if there is another instance running
   * https://stackoverflow.com/a/5339606.
   */

  int pid_file = open(config.getPidFile().c_str(), O_CREAT | O_RDWR, 0666);
  int rc = flock(pid_file, LOCK_EX | LOCK_NB);
  if (rc) {
    if (EWOULDBLOCK == errno) {
      unsigned long other_pid;
      FILE *pif_file_f = fdopen(pid_file, "r");
      fscanf(pif_file_f, "%lu", &other_pid);
      logger->critical(
          "There is another polycube instance running with pid {0}", other_pid);
      exit(EXIT_FAILURE);
    }
  }

  // write pid on .pid file (done after deamonize as pid changes)
  dprintf(pid_file, "%lu\n", (unsigned long)getpid());

  // Each instance of a service requires a high number of file descriptors
  // (for example helloworld required 7), hence the default limit is too low
  // for creating many instances of the services.
  struct rlimit r = {32 * 1024, 64 * 1024};
  if (setrlimit(RLIMIT_NOFILE, &r)) {
    logger->critical("Failed to set max number of possible filedescriptor");
    return -1;
  }

  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = shutdown_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);
  sigaction(SIGTERM, &sigIntHandler, NULL);

  try {
    PatchPanel::get_tc_instance();
    PatchPanel::get_xdp_instance();
    Controller::get_tc_instance();
    Controller::get_xdp_instance();
  } catch (const std::exception &e) {
    logger->critical("Error starting polycube: {0}", e.what());
    return -1;
  }

  core = new PolycubedCore();
  // register services that are shipped with polycube
  load_services(*core);

  // setup rest server
  int thr = 4;
  Address addr(config.getServerIP(), Pistache::Port(config.getServerPort()));

  // logger->info("Cores = {0}", hardware_concurrency());
  // logger->info("Using {0} threads", thr);

  // start rest server
  restserver = new RestServer(addr, *core);
  restserver->init(thr, config.getCertPath(), config.getKeyPath(),
                   config.getCACertPath(), config.getCertWhitelistPath(),
                   config.getCertBlacklistPath());
  restserver->start();

  // pause the execution of current thread until ctrl+c
  pause();

  // shutdown all servers components
  shutdown();

  return 0;
}
