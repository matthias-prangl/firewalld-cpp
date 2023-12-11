#pragma once

#include "firewalld_config_zone_interface.h"

namespace firewalld::config {

class Zone;

class ZonePrivate : public QObject {
  Q_OBJECT

public:
  explicit ZonePrivate(const QString &path, Zone *q);
  ~ZonePrivate() override;
  void init();

  bool builtin;
  bool isDefault;
  QString filename;
  QString name;
  QString path;
  QString uni;

  OrgFedoraprojectFirewallD1ConfigZoneInterface zoneIface_;
  Zone *q_ptr;

  Q_DECLARE_PUBLIC(Zone)

  void propertyChanged(const QString &property, const QVariant &value);

public slots:
  void zoneRemoved(const QString &name);
  void zoneRenamed(const QString &name);
  void zoneUpdated(const QString &name);

  void dbusPropertiesChanged(const QString &interfaceName,
                             const QVariantMap &properties,
                             const QStringList &invalidatedProperties);
};
} // namespace firewalld::config
