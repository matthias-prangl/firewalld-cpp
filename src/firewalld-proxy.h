#pragma once

#include "firewalld-gen.h"
#include <sdbus-c++/sdbus-c++.h>

class FirewallDProxy
    : public sdbus::ProxyInterfaces<org::fedoraproject::FirewallD1_proxy> {
public:
  FirewallDProxy(std::string destination, std::string objectPath);

  ~FirewallDProxy();

  void onReloaded();
  void onPanicModeEnabled();
  void onPanicModeDisabled();
  void onLogDeniedChanged(const std::string &value);
  void onAutomaticHelpersChanged(const std::string &value);
  void onDefaultZoneChanged(const std::string &zone);
};
