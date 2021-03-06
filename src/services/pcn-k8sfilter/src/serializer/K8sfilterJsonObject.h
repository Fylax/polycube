/**
* k8sfilter API
* Kubernetes Traffic Filtering Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* K8sfilterJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"

#include "PortsJsonObject.h"
#include <vector>
#include "polycube/services/cube.h"

using polycube::service::CubeType;

namespace io {
namespace swagger {
namespace server {
namespace model {

enum class K8sfilterLoglevelEnum {
  TRACE, DEBUG, INFO, WARN, ERR, CRITICAL, OFF
};

/// <summary>
///
/// </summary>
class  K8sfilterJsonObject : public JsonObjectBase {
public:
  K8sfilterJsonObject();
  K8sfilterJsonObject(nlohmann::json& json);
  ~K8sfilterJsonObject() final = default;

  /////////////////////////////////////////////
  /// JsonObjectBase overrides

  nlohmann::json toJson() const final;

  static nlohmann::json helpKeys();
  static nlohmann::json helpElements();
  static nlohmann::json helpWritableLeafs();
  static nlohmann::json helpComplexElements();
  static std::vector<std::string> helpActions();
  /////////////////////////////////////////////
  /// K8sfilterJsonObject members

  /// <summary>
  /// Name of the k8sfilter service
  /// </summary>
  std::string getName() const;
  void setName(std::string value);
  bool nameIsSet() const;
  void unsetName();

  /// <summary>
  /// UUID of the Cube
  /// </summary>
  std::string getUuid() const;
  void setUuid(std::string value);
  bool uuidIsSet() const;
  void unsetUuid();

  /// <summary>
  /// Type of the Cube (TC, XDP_SKB, XDP_DRV)
  /// </summary>
  CubeType getType() const;
  void setType(CubeType value);
  bool typeIsSet() const;
  void unsetType();
  static std::string CubeType_to_string(const CubeType &value);
  static CubeType string_to_CubeType(const std::string &str);

  /// <summary>
  /// Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
  /// </summary>
  K8sfilterLoglevelEnum getLoglevel() const;
  void setLoglevel(K8sfilterLoglevelEnum value);
  bool loglevelIsSet() const;
  void unsetLoglevel();
  static std::string K8sfilterLoglevelEnum_to_string(const K8sfilterLoglevelEnum &value);
  static K8sfilterLoglevelEnum string_to_K8sfilterLoglevelEnum(const std::string &str);
  polycube::LogLevel getPolycubeLoglevel() const;
  /// <summary>
  /// Entry of the ports table
  /// </summary>
  const std::vector<PortsJsonObject>& getPorts() const;
  void addPorts(PortsJsonObject value);
  bool portsIsSet() const;
  void unsetPorts();

  /// <summary>
  /// Port range used for NodePort services
  /// </summary>
  std::string getNodeportRange() const;
  void setNodeportRange(std::string value);
  bool nodeportRangeIsSet() const;
  void unsetNodeportRange();


private:
  std::string m_name;
  bool m_nameIsSet;
  std::string m_uuid;
  bool m_uuidIsSet;
  CubeType m_type;
  bool m_typeIsSet;
  K8sfilterLoglevelEnum m_loglevel;
  bool m_loglevelIsSet;
  std::vector<PortsJsonObject> m_ports;
  bool m_portsIsSet;
  std::string m_nodeportRange;
  bool m_nodeportRangeIsSet;
};

}
}
}
}

