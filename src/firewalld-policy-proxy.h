#pragma once

#include "firewalld-gen.h"
#include <sdbus-c++/sdbus-c++.h>

class FirewallDPolicyProxy : public sdbus::ProxyInterfaces<
                                 org::fedoraproject::FirewallD1::policy_proxy> {
public:
  FirewallDPolicyProxy(std::string destination, std::string objectPath)
      : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~FirewallDPolicyProxy() { unregisterProxy(); }
};
