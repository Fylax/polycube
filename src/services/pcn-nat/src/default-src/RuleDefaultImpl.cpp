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


// These methods have a default implementation. Your are free to keep it or add your own


#include "../Rule.h"



std::shared_ptr<RuleSnat> Rule::getSnat(){
  return RuleSnat::getEntry(*this);
}

void Rule::addSnat(const RuleSnatJsonObject &value){
  RuleSnat::create(*this, value);
}

void Rule::replaceSnat(const RuleSnatJsonObject &conf){
  RuleSnat::removeEntry(*this);
  RuleSnat::create(*this, conf);
}

void Rule::delSnat(){
  RuleSnat::removeEntry(*this);
}


std::shared_ptr<RuleMasquerade> Rule::getMasquerade(){
  return RuleMasquerade::getEntry(*this);
}

void Rule::addMasquerade(const RuleMasqueradeJsonObject &value){
  RuleMasquerade::create(*this, value);
}

void Rule::replaceMasquerade(const RuleMasqueradeJsonObject &conf){
  RuleMasquerade::removeEntry(*this);
  RuleMasquerade::create(*this, conf);
}

void Rule::delMasquerade(){
  RuleMasquerade::removeEntry(*this);
}


std::shared_ptr<RuleDnat> Rule::getDnat(){
  return RuleDnat::getEntry(*this);
}

void Rule::addDnat(const RuleDnatJsonObject &value){
  RuleDnat::create(*this, value);
}

void Rule::replaceDnat(const RuleDnatJsonObject &conf){
  RuleDnat::removeEntry(*this);
  RuleDnat::create(*this, conf);
}

void Rule::delDnat(){
  RuleDnat::removeEntry(*this);
}


std::shared_ptr<RulePortForwarding> Rule::getPortForwarding(){
  return RulePortForwarding::getEntry(*this);
}

void Rule::addPortForwarding(const RulePortForwardingJsonObject &value){
  RulePortForwarding::create(*this, value);
}

void Rule::replacePortForwarding(const RulePortForwardingJsonObject &conf){
  RulePortForwarding::removeEntry(*this);
  RulePortForwarding::create(*this, conf);
}

void Rule::delPortForwarding(){
  RulePortForwarding::removeEntry(*this);
}




