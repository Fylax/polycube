/**
* bridge API
* bridge API generated from bridge.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
*/

/* Do not edit this file manually */

#include "PortsStpSchema.h"

namespace io {
namespace swagger {
namespace server {
namespace model {

PortsStpSchema::PortsStpSchema() {
  m_State = "";
  m_StateIsSet = false;
  m_Vlan = 0;
  m_VlanIsSet = false;
  m_Pathcost = 0;
  m_PathcostIsSet = false;
  m_Portpriority = 0;
  m_PortpriorityIsSet = false;
}

PortsStpSchema::~PortsStpSchema() {}

void PortsStpSchema::validate() {
  // TODO: implement validation
}

nlohmann::json PortsStpSchema::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_StateIsSet) {
    val["state"] = m_State;
  }

  if (m_VlanIsSet) {
    val["vlan"] = m_Vlan;
  }

  if (m_PathcostIsSet) {
    val["pathcost"] = m_Pathcost;
  }

  if (m_PortpriorityIsSet) {
    val["portpriority"] = m_Portpriority;
  }

  return val;
}

void PortsStpSchema::fromJson(nlohmann::json &val) {
  if (val.find("state") != val.end()) {
    setState(val.at("state"));
  }

  if (val.find("vlan") != val.end()) {
    setVlan(val.at("vlan"));
  }

  if (val.find("pathcost") != val.end()) {
    setPathcost(val.at("pathcost"));
  }

  if (val.find("portpriority") != val.end()) {
    setPortpriority(val.at("portpriority"));
  }
}

nlohmann::json PortsStpSchema::getKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["vlan"]["name"] = "vlan";
  val["vlan"]["type"] = "key";
  val["vlan"]["simpletype"] = "integer";
  val["vlan"]["description"] =
      R"POLYCUBE(VLAN identifier for this entry)POLYCUBE";
  val["vlan"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json PortsStpSchema::getElements() {
  nlohmann::json val = nlohmann::json::object();

  val["state"]["name"] = "state";
  val["state"]["type"] = "leaf";  // Suppose that type is leaf
  val["state"]["simpletype"] = "string";
  val["state"]["description"] = R"POLYCUBE(STP port state)POLYCUBE";
  val["state"]["example"] = R"POLYCUBE()POLYCUBE";
  val["state"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "string",
  "description" : "STP port state",
  "readOnly" : true,
  "enum" : [ "disabled", "blocking", "listening", "learning", "forwarding" ]
})POLYCUBE");
  val["pathcost"]["name"] = "pathcost";
  val["pathcost"]["type"] = "leaf";  // Suppose that type is leaf
  val["pathcost"]["simpletype"] = "integer";
  val["pathcost"]["description"] =
      R"POLYCUBE(STP cost associated with this interface)POLYCUBE";
  val["pathcost"]["example"] = R"POLYCUBE()POLYCUBE";
  val["pathcost"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "integer",
  "format" : "uint32",
  "description" : "STP cost associated with this interface"
})POLYCUBE");
  val["portpriority"]["name"] = "portpriority";
  val["portpriority"]["type"] = "leaf";  // Suppose that type is leaf
  val["portpriority"]["simpletype"] = "integer";
  val["portpriority"]["description"] =
      R"POLYCUBE(Port priority of this interface)POLYCUBE";
  val["portpriority"]["example"] = R"POLYCUBE()POLYCUBE";
  val["portpriority"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "integer",
  "format" : "uint32",
  "description" : "Port priority of this interface"
})POLYCUBE");

  return val;
}

nlohmann::json PortsStpSchema::getWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["pathcost"]["name"] = "pathcost";
  val["pathcost"]["simpletype"] = "integer";
  val["pathcost"]["description"] =
      R"POLYCUBE(STP cost associated with this interface)POLYCUBE";
  val["pathcost"]["example"] = R"POLYCUBE()POLYCUBE";
  val["pathcost"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "integer",
  "format" : "uint32",
  "description" : "STP cost associated with this interface"
})POLYCUBE");
  val["portpriority"]["name"] = "portpriority";
  val["portpriority"]["simpletype"] = "integer";
  val["portpriority"]["description"] =
      R"POLYCUBE(Port priority of this interface)POLYCUBE";
  val["portpriority"]["example"] = R"POLYCUBE()POLYCUBE";
  val["portpriority"]["jsonSchema"] = nlohmann::json::parse(R"POLYCUBE({
  "type" : "integer",
  "format" : "uint32",
  "description" : "Port priority of this interface"
})POLYCUBE");

  return val;
}

nlohmann::json PortsStpSchema::getComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  return val;
}

std::string PortsStpSchema::getState() const {
  return m_State;
}

void PortsStpSchema::setState(std::string value) {
  m_State = value;
  m_StateIsSet = true;
}

bool PortsStpSchema::stateIsSet() const {
  return m_StateIsSet;
}

void PortsStpSchema::unsetState() {
  m_StateIsSet = false;
}
int32_t PortsStpSchema::getVlan() const {
  return m_Vlan;
}

void PortsStpSchema::setVlan(int32_t value) {
  m_Vlan = value;
  m_VlanIsSet = true;
}

bool PortsStpSchema::vlanIsSet() const {
  return m_VlanIsSet;
}

void PortsStpSchema::unsetVlan() {
  m_VlanIsSet = false;
}
int32_t PortsStpSchema::getPathcost() const {
  return m_Pathcost;
}

void PortsStpSchema::setPathcost(int32_t value) {
  m_Pathcost = value;
  m_PathcostIsSet = true;
}

bool PortsStpSchema::pathcostIsSet() const {
  return m_PathcostIsSet;
}

void PortsStpSchema::unsetPathcost() {
  m_PathcostIsSet = false;
}
int32_t PortsStpSchema::getPortpriority() const {
  return m_Portpriority;
}

void PortsStpSchema::setPortpriority(int32_t value) {
  m_Portpriority = value;
  m_PortpriorityIsSet = true;
}

bool PortsStpSchema::portpriorityIsSet() const {
  return m_PortpriorityIsSet;
}

void PortsStpSchema::unsetPortpriority() {
  m_PortpriorityIsSet = false;
}
}
}
}
}
