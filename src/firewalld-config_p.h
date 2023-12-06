#pragma once

#include "dbus/firewalld_config_interface.h"
#include "firewalld-config-zone.h"

namespace firewalld::config {

class FirewallDConfigPrivate : public QObject {
  Q_OBJECT

public:
  FirewallDConfigPrivate();

  OrgFedoraprojectFirewallD1ConfigInterface iface_;
  QMap<QString, QSharedPointer<Zone>> zoneMap_;

private slots:
  void init();
};
} // namespace firewalld::config
