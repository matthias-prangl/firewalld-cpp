#pragma once

#include "firewalld-gen.h"
#include <sdbus-c++/sdbus-c++.h>

class FirewallDPoliciesProxy
    : public sdbus::ProxyInterfaces<
          org::fedoraproject::FirewallD1::policies_proxy> {
public:
  FirewallDPoliciesProxy(std::string destination, std::string objectPath)
      : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~FirewallDPoliciesProxy() { unregisterProxy(); }
};
