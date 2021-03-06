/**
* simplebridge API
* Simple L2 Bridge Service
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "FdbEntryJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

FdbEntryJsonObject::FdbEntryJsonObject() : 
  m_addressIsSet(false),
  m_portIsSet(false),
  m_ageIsSet(false) { }

FdbEntryJsonObject::FdbEntryJsonObject(nlohmann::json &val) : 
  m_addressIsSet(false),
  m_portIsSet(false),
  m_ageIsSet(false) { 
  if (val.count("address")) {
    setAddress(val.at("address").get<std::string>());
  }

  if (val.count("port")) {
    setPort(val.at("port").get<std::string>());
  }

  if (val.count("age")) {
    setAge(val.at("age").get<uint32_t>());
  }
}

nlohmann::json FdbEntryJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_addressIsSet) {
    val["address"] = m_address;
  }

  if (m_portIsSet) {
    val["port"] = m_port;
  }

  if (m_ageIsSet) {
    val["age"] = m_age;
  }


  return val;
}

nlohmann::json FdbEntryJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["address"]["name"] = "address";
  val["address"]["type"] = "key";
  val["address"]["simpletype"] = "string";
  val["address"]["description"] = R"POLYCUBE(Address of the filtering database entry)POLYCUBE";
  val["address"]["example"] = R"POLYCUBE(C5:13:2D:36:27:9B)POLYCUBE";

  return val;
}

nlohmann::json FdbEntryJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["port"]["name"] = "port";
  val["port"]["type"] = "leaf"; // Suppose that type is leaf
  val["port"]["simpletype"] = "string";
  val["port"]["description"] = R"POLYCUBE(Output port name)POLYCUBE";
  val["port"]["example"] = R"POLYCUBE(port2)POLYCUBE";
  val["age"]["name"] = "age";
  val["age"]["type"] = "leaf"; // Suppose that type is leaf
  val["age"]["simpletype"] = "integer";
  val["age"]["description"] = R"POLYCUBE(Age of the current filtering database entry)POLYCUBE";
  val["age"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json FdbEntryJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["port"]["name"] = "port";
  val["port"]["simpletype"] = "string";
  val["port"]["description"] = R"POLYCUBE(Output port name)POLYCUBE";
  val["port"]["example"] = R"POLYCUBE(port2)POLYCUBE";

  return val;
}

nlohmann::json FdbEntryJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> FdbEntryJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string FdbEntryJsonObject::getAddress() const {
  return m_address;
}

void FdbEntryJsonObject::setAddress(std::string value) {
  m_address = value;
  m_addressIsSet = true;
}

bool FdbEntryJsonObject::addressIsSet() const {
  return m_addressIsSet;
}





std::string FdbEntryJsonObject::getPort() const {
  return m_port;
}

void FdbEntryJsonObject::setPort(std::string value) {
  m_port = value;
  m_portIsSet = true;
}

bool FdbEntryJsonObject::portIsSet() const {
  return m_portIsSet;
}





uint32_t FdbEntryJsonObject::getAge() const {
  return m_age;
}

void FdbEntryJsonObject::setAge(uint32_t value) {
  m_age = value;
  m_ageIsSet = true;
}

bool FdbEntryJsonObject::ageIsSet() const {
  return m_ageIsSet;
}

void FdbEntryJsonObject::unsetAge() {
  m_ageIsSet = false;
}




}
}
}
}

