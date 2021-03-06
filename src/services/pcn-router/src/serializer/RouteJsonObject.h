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

/*
* RouteJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace io {
namespace swagger {
namespace server {
namespace model {


/// <summary>
///
/// </summary>
class  RouteJsonObject : public JsonObjectBase {
public:
  RouteJsonObject();
  RouteJsonObject(nlohmann::json& json);
  ~RouteJsonObject() final = default;

  /////////////////////////////////////////////
  /// JsonObjectBase overrides

  nlohmann::json toJson() const final;

  static nlohmann::json helpKeys();
  static nlohmann::json helpElements();
  static nlohmann::json helpWritableLeafs();
  static nlohmann::json helpComplexElements();
  static std::vector<std::string> helpActions();
  /////////////////////////////////////////////
  /// RouteJsonObject members

  /// <summary>
  /// Destination network IP
  /// </summary>
  std::string getNetwork() const;
  void setNetwork(std::string value);
  bool networkIsSet() const;
  void unsetNetwork();

  /// <summary>
  /// Destination network netmask
  /// </summary>
  std::string getNetmask() const;
  void setNetmask(std::string value);
  bool netmaskIsSet() const;
  void unsetNetmask();

  /// <summary>
  /// Next hop; if destination is local will be shown &#39;local&#39; instead of the ip address
  /// </summary>
  std::string getNexthop() const;
  void setNexthop(std::string value);
  bool nexthopIsSet() const;
  void unsetNexthop();

  /// <summary>
  /// Outgoing interface
  /// </summary>
  std::string getInterface() const;
  void setInterface(std::string value);
  bool interfaceIsSet() const;
  void unsetInterface();

  /// <summary>
  /// Cost of this route
  /// </summary>
  int32_t getPathcost() const;
  void setPathcost(int32_t value);
  bool pathcostIsSet() const;
  void unsetPathcost();


private:
  std::string m_network;
  bool m_networkIsSet;
  std::string m_netmask;
  bool m_netmaskIsSet;
  std::string m_nexthop;
  bool m_nexthopIsSet;
  std::string m_interface;
  bool m_interfaceIsSet;
  int32_t m_pathcost;
  bool m_pathcostIsSet;
};

}
}
}
}

