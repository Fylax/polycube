/**
* router API
* Router Service
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
  m_nameIsSet (false),
  m_uuidIsSet (false),
  m_statusIsSet (false),
  m_peerIsSet (false),
  m_ipIsSet (false),
  m_netmaskIsSet (false),
  m_secondaryipIsSet (false),
  m_macIsSet (false) { }

PortsJsonObject::PortsJsonObject(nlohmann::json& val) :
  m_nameIsSet (false),
  m_uuidIsSet (false),
  m_statusIsSet (false),
  m_peerIsSet (false),
  // Mandatory item
  m_ip (val.at("ip").get<std::string>()),
  m_ipIsSet (true),
  // Mandatory item
  m_netmask (val.at("netmask").get<std::string>()),
  m_netmaskIsSet (true),
  m_secondaryipIsSet (false),
  m_macIsSet (false) {

  if (val.count("uuid") != 0) {
    setUuid(val.at("uuid").get<std::string>());
  }

  if (val.count("status") != 0) {
    setStatus(string_to_PortsStatusEnum(val.at("status").get<std::string>()));
  }

  if (val.count("peer") != 0) {
    setPeer(val.at("peer").get<std::string>());
  }



  m_secondaryip.clear();
  for (auto& item : val["secondaryip"]) {
    PortsSecondaryipJsonObject newItem { item };
    m_secondaryip.push_back(newItem);
  }
  m_secondaryipIsSet = !m_secondaryip.empty();


  if (val.count("mac") != 0) {
    setMac(val.at("mac").get<std::string>());
  }
}

nlohmann::json PortsJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  val["name"] = m_name;
  if (m_uuidIsSet) {
    val["uuid"] = m_uuid;
  }

  if (m_statusIsSet) {
    val["status"] = PortsStatusEnum_to_string(m_status);
  }

  if (m_peerIsSet) {
    val["peer"] = m_peer;
  }

  val["ip"] = m_ip;
  val["netmask"] = m_netmask;
  {
    nlohmann::json jsonArray;
    for (auto& item : m_secondaryip) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["secondaryip"] = jsonArray;
    }
  }
  if (m_macIsSet) {
    val["mac"] = m_mac;
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
  val["ip"]["name"] = "ip";
  val["ip"]["type"] = "leaf"; // Suppose that type is leaf
  val["ip"]["simpletype"] = "string";
  val["ip"]["description"] = R"POLYCUBE(IP address of the port)POLYCUBE";
  val["ip"]["example"] = R"POLYCUBE(207.46.130.1)POLYCUBE";
  val["netmask"]["name"] = "netmask";
  val["netmask"]["type"] = "leaf"; // Suppose that type is leaf
  val["netmask"]["simpletype"] = "string";
  val["netmask"]["description"] = R"POLYCUBE(Netmask of the port)POLYCUBE";
  val["netmask"]["example"] = R"POLYCUBE(255.255.255.0)POLYCUBE";
  val["secondaryip"]["name"] = "secondaryip";
  val["secondaryip"]["type"] = "leaf"; // Suppose that type is leaf
  val["secondaryip"]["type"] = "list";
  val["secondaryip"]["description"] = R"POLYCUBE(Secondary IP address for the port)POLYCUBE";
  val["secondaryip"]["example"] = R"POLYCUBE()POLYCUBE";
  val["mac"]["name"] = "mac";
  val["mac"]["type"] = "leaf"; // Suppose that type is leaf
  val["mac"]["simpletype"] = "string";
  val["mac"]["description"] = R"POLYCUBE(MAC address of the port)POLYCUBE";
  val["mac"]["example"] = R"POLYCUBE(B3:23:45:F5:3A)POLYCUBE";

  return val;
}

nlohmann::json PortsJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["peer"]["name"] = "peer";
  val["peer"]["simpletype"] = "string";
  val["peer"]["description"] = R"POLYCUBE(Peer name, such as a network interfaces (e.g., 'veth0') or another cube (e.g., 'br1:port2'))POLYCUBE";
  val["peer"]["example"] = R"POLYCUBE(r0:port1)POLYCUBE";
  val["ip"]["name"] = "ip";
  val["ip"]["simpletype"] = "string";
  val["ip"]["description"] = R"POLYCUBE(IP address of the port)POLYCUBE";
  val["ip"]["example"] = R"POLYCUBE(207.46.130.1)POLYCUBE";
  val["netmask"]["name"] = "netmask";
  val["netmask"]["simpletype"] = "string";
  val["netmask"]["description"] = R"POLYCUBE(Netmask of the port)POLYCUBE";
  val["netmask"]["example"] = R"POLYCUBE(255.255.255.0)POLYCUBE";
  val["mac"]["name"] = "mac";
  val["mac"]["simpletype"] = "string";
  val["mac"]["description"] = R"POLYCUBE(MAC address of the port)POLYCUBE";
  val["mac"]["example"] = R"POLYCUBE(B3:23:45:F5:3A)POLYCUBE";

  return val;
}

nlohmann::json PortsJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  val["secondaryip"]["name"] = "secondaryip";
  val["secondaryip"]["type"] = "list";
  val["secondaryip"]["description"] = R"POLYCUBE(Secondary IP address for the port)POLYCUBE";
  val["secondaryip"]["example"] = R"POLYCUBE()POLYCUBE";

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



std::string PortsJsonObject::getIp() const {
  return m_ip;
}

void PortsJsonObject::setIp(std::string value) {
  m_ip = value;
  m_ipIsSet = true;
}

bool PortsJsonObject::ipIsSet() const {
  return m_ipIsSet;
}





std::string PortsJsonObject::getNetmask() const {
  return m_netmask;
}

void PortsJsonObject::setNetmask(std::string value) {
  m_netmask = value;
  m_netmaskIsSet = true;
}

bool PortsJsonObject::netmaskIsSet() const {
  return m_netmaskIsSet;
}





const std::vector<PortsSecondaryipJsonObject>& PortsJsonObject::getSecondaryip() const{
  return m_secondaryip;
}

void PortsJsonObject::addPortsSecondaryip(PortsSecondaryipJsonObject value) {
  m_secondaryip.push_back(value);
}


bool PortsJsonObject::secondaryipIsSet() const {
  return m_secondaryipIsSet;
}

void PortsJsonObject::unsetSecondaryip() {
  m_secondaryipIsSet = false;
}



std::string PortsJsonObject::getMac() const {
  return m_mac;
}

void PortsJsonObject::setMac(std::string value) {
  m_mac = value;
  m_macIsSet = true;
}

bool PortsJsonObject::macIsSet() const {
  return m_macIsSet;
}

void PortsJsonObject::unsetMac() {
  m_macIsSet = false;
}




}
}
}
}


