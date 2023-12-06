#pragma once

#include "dbus/firewalld_config_zone_interface.h"
#include "firewalld-config-zone.h"

namespace firewalld::config {
class ZonePrivate : public QObject {
  Q_OBJECT

public:
  explicit ZonePrivate(const QString &path, Zone *q);
  ~ZonePrivate() override;
  void init();

  OrgFedoraprojectFirewallD1ConfigZoneInterface zoneIface_;
  Zone *q_ptr;

  Q_DECLARE_PUBLIC(Zone)
};
} // namespace firewalld::config
