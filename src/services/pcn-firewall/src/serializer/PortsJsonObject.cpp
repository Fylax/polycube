/**
* firewall API
* Firewall Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "PortsJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

PortsJsonObject::PortsJsonObject() : 
  m_nameIsSet(false),
  m_uuidIsSet(false),
  m_statusIsSet(false),
  m_peerIsSet(false) { }

PortsJsonObject::PortsJsonObject(nlohmann::json &val) : 
  m_nameIsSet(false),
  m_uuidIsSet(false),
  m_statusIsSet(false),
  m_peerIsSet(false) { 
  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }

  if (val.count("uuid")) {
    setUuid(val.at("uuid").get<std::string>());
  }

  if (val.count("status")) {
    setStatus(string_to_PortsStatusEnum(val.at("status").get<std::string>()));
  }

  if (val.count("peer")) {
    setPeer(val.at("peer").get<std::string>());
  }
}

nlohmann::json PortsJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  if (m_uuidIsSet) {
    val["uuid"] = m_uuid;
  }

  if (m_statusIsSet) {
    val["status"] = PortsStatusEnum_to_string(m_status);
  }

  if (m_peerIsSet) {
    val["peer"] = m_peer;
  }


  return val;
}

nlohmann::json PortsJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["name"]["name"] = "name";
  val["name"]["type"] = "key";
  val["name"]["simpletype"] = "string";
  val["name"]["description"] = R"POLYCUBE(Port Name)POLYCUBE";
  val["name"]["example"] = R"POLYCUBE(port1)POLYCUBE";

  return val;
}

nlohmann::json PortsJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["uuid"]["name"] = "uuid";
  val["uuid"]["type"] = "leaf"; // Suppose that type is leaf
  val["uuid"]["simpletype"] = "string";
  val["uuid"]["description"] = R"POLYCUBE(UUID of the port)POLYCUBE";
  val["uuid"]["example"] = R"POLYCUBE()POLYCUBE";
  val["status"]["name"] = "status";
  val["status"]["type"] = "leaf"; // Suppose that type is leaf
  val["status"]["simpletype"] = "string";
  val["status"]["description"] = R"POLYCUBE(Status of the port (UP or DOWN))POLYCUBE";
  val["status"]["example"] = R"POLYCUBE()POLYCUBE";
  val["peer"]["name"] = "peer";
  val["peer"]["type"] = "leaf"; // Suppose that type is leaf
  val["peer"]["simpletype"] = "string";
  val["peer"]["description"] = R"POLYCUBE(Peer name, such as a network interfaces (e.g., 'veth0') or another cube (e.g., 'br1:port2'))POLYCUBE";
  val["peer"]["example"] = R"POLYCUBE(r0:port1)POLYCUBE";

  return val;
}

nlohmann::json PortsJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["peer"]["name"] = "peer";
  val["peer"]["simpletype"] = "string";
  val["peer"]["description"] = R"POLYCUBE(Peer name, such as a network interfaces (e.g., 'veth0') or another cube (e.g., 'br1:port2'))POLYCUBE";
  val["peer"]["example"] = R"POLYCUBE(r0:port1)POLYCUBE";

  return val;
}

nlohmann::json PortsJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> PortsJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string PortsJsonObject::getName() const {
  return m_name;
}

void PortsJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool PortsJsonObject::nameIsSet() const {
  return m_nameIsSet;
}





std::string PortsJsonObject::getUuid() const {
  return m_uuid;
}

void PortsJsonObject::setUuid(std::string value) {
  m_uuid = value;
  m_uuidIsSet = true;
}

bool PortsJsonObject::uuidIsSet() const {
  return m_uuidIsSet;
}

void PortsJsonObject::unsetUuid() {
  m_uuidIsSet = false;
}



PortsStatusEnum PortsJsonObject::getStatus() const {
  return m_status;
}

void PortsJsonObject::setStatus(PortsStatusEnum value) {
  m_status = value;
  m_statusIsSet = true;
}

bool PortsJsonObject::statusIsSet() const {
  return m_statusIsSet;
}

void PortsJsonObject::unsetStatus() {
  m_statusIsSet = false;
}

std::string PortsJsonObject::PortsStatusEnum_to_string(const PortsStatusEnum &value){
  switch(value){
    case PortsStatusEnum::UP:
      return std::string("up");
    case PortsStatusEnum::DOWN:
      return std::string("down");
    default:
      throw std::runtime_error("Bad Ports status");
  }
}

PortsStatusEnum PortsJsonObject::string_to_PortsStatusEnum(const std::string &str){
  if (JsonObjectBase::iequals("up", str))
    return PortsStatusEnum::UP;
  if (JsonObjectBase::iequals("down", str))
    return PortsStatusEnum::DOWN;
  throw std::runtime_error("Ports status is invalid");
}


std::string PortsJsonObject::getPeer() const {
  return m_peer;
}

void PortsJsonObject::setPeer(std::string value) {
  m_peer = value;
  m_peerIsSet = true;
}

bool PortsJsonObject::peerIsSet() const {
  return m_peerIsSet;
}

void PortsJsonObject::unsetPeer() {
  m_peerIsSet = false;
}




}
}
}
}

