#pragma once

#include "firewalld-gen.h"
#include <sdbus-c++/sdbus-c++.h>

class FirewallDIPSetProxy : public sdbus::ProxyInterfaces<
                                org::fedoraproject::FirewallD1::ipset_proxy> {
public:
  FirewallDIPSetProxy(std::string destination, std::string objectPath)
      : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~FirewallDIPSetProxy() { unregisterProxy(); }
};
