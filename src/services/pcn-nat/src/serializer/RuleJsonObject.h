/**
* nat API
* NAT Service
*
* OpenAPI spec version: 1.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* RuleJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "RuleMasqueradeJsonObject.h"
#include "RulePortForwardingJsonObject.h"
#include "RuleDnatJsonObject.h"
#include "RuleSnatJsonObject.h"

namespace io {
namespace swagger {
namespace server {
namespace model {


/// <summary>
///
/// </summary>
class  RuleJsonObject : public JsonObjectBase {
public:
  RuleJsonObject();
  RuleJsonObject(nlohmann::json& json);
  ~RuleJsonObject() final = default;

  /////////////////////////////////////////////
  /// JsonObjectBase overrides

  nlohmann::json toJson() const final;

  static nlohmann::json helpKeys();
  static nlohmann::json helpElements();
  static nlohmann::json helpWritableLeafs();
  static nlohmann::json helpComplexElements();
  static std::vector<std::string> helpActions();
  /////////////////////////////////////////////
  /// RuleJsonObject members

  /// <summary>
  ///
  /// </summary>
  RuleSnatJsonObject getSnat() const;
  void setSnat(RuleSnatJsonObject value);
  bool snatIsSet() const;
  void unsetSnat();

  /// <summary>
  ///
  /// </summary>
  RuleMasqueradeJsonObject getMasquerade() const;
  void setMasquerade(RuleMasqueradeJsonObject value);
  bool masqueradeIsSet() const;
  void unsetMasquerade();

  /// <summary>
  ///
  /// </summary>
  RuleDnatJsonObject getDnat() const;
  void setDnat(RuleDnatJsonObject value);
  bool dnatIsSet() const;
  void unsetDnat();

  /// <summary>
  ///
  /// </summary>
  RulePortForwardingJsonObject getPortForwarding() const;
  void setPortForwarding(RulePortForwardingJsonObject value);
  bool portForwardingIsSet() const;
  void unsetPortForwarding();


private:
  RuleSnatJsonObject m_snat;
  bool m_snatIsSet;
  RuleMasqueradeJsonObject m_masquerade;
  bool m_masqueradeIsSet;
  RuleDnatJsonObject m_dnat;
  bool m_dnatIsSet;
  RulePortForwardingJsonObject m_portForwarding;
  bool m_portForwardingIsSet;
};

}
}
}
}

