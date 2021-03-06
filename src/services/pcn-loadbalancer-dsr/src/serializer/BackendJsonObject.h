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
* BackendJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "BackendPoolJsonObject.h"
#include <vector>

namespace io {
namespace swagger {
namespace server {
namespace model {


/// <summary>
///
/// </summary>
class  BackendJsonObject : public JsonObjectBase {
public:
  BackendJsonObject();
  BackendJsonObject(nlohmann::json& json);
  ~BackendJsonObject() final = default;

  /////////////////////////////////////////////
  /// JsonObjectBase overrides

  nlohmann::json toJson() const final;

  static nlohmann::json helpKeys();
  static nlohmann::json helpElements();
  static nlohmann::json helpWritableLeafs();
  static nlohmann::json helpComplexElements();
  static std::vector<std::string> helpActions();
  /////////////////////////////////////////////
  /// BackendJsonObject members

  /// <summary>
  /// pool of backend servers serving requests
  /// </summary>
  const std::vector<BackendPoolJsonObject>& getPool() const;
  void addBackendPool(BackendPoolJsonObject value);
  bool poolIsSet() const;
  void unsetPool();


private:
  std::vector<BackendPoolJsonObject> m_pool;
  bool m_poolIsSet;
};

}
}
}
}

