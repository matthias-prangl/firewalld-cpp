#pragma once

#include "firewalld-gen.h"
#include <sdbus-c++/sdbus-c++.h>

class FirewallDZoneProxy : public sdbus::ProxyInterfaces<
                               org::fedoraproject::FirewallD1::zone_proxy> {
public:
  FirewallDZoneProxy(std::string destination, std::string objectPath)
      : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~FirewallDZoneProxy() { unregisterProxy(); }
};
