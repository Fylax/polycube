/**
* lbdsr API
* LoadBalancer Direct Server Return Service
*
* OpenAPI spec version: 2.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* LbdsrApiImpl.h
*
*
*/

#pragma once


#include <memory>
#include <map>
#include <mutex>
#include "../Lbdsr.h"

#include "BackendJsonObject.h"
#include "BackendPoolJsonObject.h"
#include "FrontendJsonObject.h"
#include "LbdsrJsonObject.h"
#include "PortsJsonObject.h"
#include <vector>

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

namespace LbdsrApiImpl {
  void create_lbdsr_backend_by_id(const std::string &name, const BackendJsonObject &value);
  void create_lbdsr_backend_pool_by_id(const std::string &name, const uint32_t &id, const BackendPoolJsonObject &value);
  void create_lbdsr_backend_pool_list_by_id(const std::string &name, const std::vector<BackendPoolJsonObject> &value);
  void create_lbdsr_by_id(const std::string &name, const LbdsrJsonObject &value);
  void create_lbdsr_frontend_by_id(const std::string &name, const FrontendJsonObject &value);
  void create_lbdsr_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void create_lbdsr_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void delete_lbdsr_backend_by_id(const std::string &name);
  void delete_lbdsr_backend_pool_by_id(const std::string &name, const uint32_t &id);
  void delete_lbdsr_backend_pool_list_by_id(const std::string &name);
  void delete_lbdsr_by_id(const std::string &name);
  void delete_lbdsr_frontend_by_id(const std::string &name);
  void delete_lbdsr_ports_by_id(const std::string &name, const std::string &portsName);
  void delete_lbdsr_ports_list_by_id(const std::string &name);
  std::string read_lbdsr_algorithm_by_id(const std::string &name);
  BackendJsonObject read_lbdsr_backend_by_id(const std::string &name);
  BackendPoolJsonObject read_lbdsr_backend_pool_by_id(const std::string &name, const uint32_t &id);
  std::vector<BackendPoolJsonObject> read_lbdsr_backend_pool_list_by_id(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_lbdsr_backend_pool_list_by_id_get_list(const std::string &name);
  std::string read_lbdsr_backend_pool_mac_by_id(const std::string &name, const uint32_t &id);
  LbdsrJsonObject read_lbdsr_by_id(const std::string &name);
  FrontendJsonObject read_lbdsr_frontend_by_id(const std::string &name);
  std::string read_lbdsr_frontend_mac_by_id(const std::string &name);
  std::string read_lbdsr_frontend_vip_by_id(const std::string &name);
  std::vector<LbdsrJsonObject> read_lbdsr_list_by_id();
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_lbdsr_list_by_id_get_list();
  LbdsrLoglevelEnum read_lbdsr_loglevel_by_id(const std::string &name);
  PortsJsonObject read_lbdsr_ports_by_id(const std::string &name, const std::string &portsName);
  std::vector<PortsJsonObject> read_lbdsr_ports_list_by_id(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_lbdsr_ports_list_by_id_get_list(const std::string &name);
  std::string read_lbdsr_ports_peer_by_id(const std::string &name, const std::string &portsName);
  PortsStatusEnum read_lbdsr_ports_status_by_id(const std::string &name, const std::string &portsName);
  PortsTypeEnum read_lbdsr_ports_type_by_id(const std::string &name, const std::string &portsName);
  std::string read_lbdsr_ports_uuid_by_id(const std::string &name, const std::string &portsName);
  CubeType read_lbdsr_type_by_id(const std::string &name);
  std::string read_lbdsr_uuid_by_id(const std::string &name);
  void replace_lbdsr_backend_by_id(const std::string &name, const BackendJsonObject &value);
  void replace_lbdsr_backend_pool_by_id(const std::string &name, const uint32_t &id, const BackendPoolJsonObject &value);
  void replace_lbdsr_backend_pool_list_by_id(const std::string &name, const std::vector<BackendPoolJsonObject> &value);
  void replace_lbdsr_by_id(const std::string &name, const LbdsrJsonObject &value);
  void replace_lbdsr_frontend_by_id(const std::string &name, const FrontendJsonObject &value);
  void replace_lbdsr_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void replace_lbdsr_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void update_lbdsr_algorithm_by_id(const std::string &name, const std::string &value);
  void update_lbdsr_backend_by_id(const std::string &name, const BackendJsonObject &value);
  void update_lbdsr_backend_pool_by_id(const std::string &name, const uint32_t &id, const BackendPoolJsonObject &value);
  void update_lbdsr_backend_pool_list_by_id(const std::string &name, const std::vector<BackendPoolJsonObject> &value);
  void update_lbdsr_by_id(const std::string &name, const LbdsrJsonObject &value);
  void update_lbdsr_frontend_by_id(const std::string &name, const FrontendJsonObject &value);
  void update_lbdsr_frontend_mac_by_id(const std::string &name, const std::string &value);
  void update_lbdsr_frontend_vip_by_id(const std::string &name, const std::string &value);
  void update_lbdsr_list_by_id(const std::vector<LbdsrJsonObject> &value);
  void update_lbdsr_loglevel_by_id(const std::string &name, const LbdsrLoglevelEnum &value);
  void update_lbdsr_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void update_lbdsr_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void update_lbdsr_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &value);
  void update_lbdsr_ports_type_by_id(const std::string &name, const std::string &portsName, const PortsTypeEnum &value);
}
}
}
}
}

