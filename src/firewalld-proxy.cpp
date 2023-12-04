#include "firewalld-proxy.h"
#include <spdlog/spdlog.h>

FirewallDProxy::FirewallDProxy(std::string destination, std::string objectPath)
    : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
  registerProxy();
}

FirewallDProxy::~FirewallDProxy() { unregisterProxy(); }

void FirewallDProxy::onReloaded() { spdlog::debug("onReloaded"); }

void FirewallDProxy::onPanicModeEnabled() {
  spdlog::debug("onPanicModeEnabled");
}

void FirewallDProxy::onPanicModeDisabled() {
  spdlog::debug("onPanicModeDisabled");
}

void FirewallDProxy::onLogDeniedChanged(const std::string &value) {
  spdlog::debug("onLogDeniedChanged {}", value);
}

void FirewallDProxy::onAutomaticHelpersChanged(const std::string &value) {
  spdlog::debug("onAutomaticHelpersChanged {}", value);
}

void FirewallDProxy::onDefaultZoneChanged(const std::string &zone) {
  spdlog::debug("onDefaultZoneChanged {}", zone);
}
