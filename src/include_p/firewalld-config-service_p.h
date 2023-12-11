#pragma once

#include "firewalld_config_service_interface.h"

namespace firewalld::config {

class Service;

class ServicePrivate : public QObject {
  Q_OBJECT

public:
  explicit ServicePrivate(const QString &path, Service *q);
  ~ServicePrivate() override;
  void init();

  bool builtin;
  bool isDefault;
  QString filename;
  QString name;
  QString path;
  QString uni;

  OrgFedoraprojectFirewallD1ConfigServiceInterface serviceIface_;
  Service *q_ptr;

  Q_DECLARE_PUBLIC(Service)

  void propertyChanged(const QString &property, const QVariant &value);

public slots:
  void serviceRemoved(const QString &name);
  void serviceRenamed(const QString &name);
  void serviceUpdated(const QString &name);
  void dbusPropertiesChanged(const QString &interfaceName,
                             const QVariantMap &properties,
                             const QStringList &invalidatedProperties);
};
} // namespace firewalld::config
