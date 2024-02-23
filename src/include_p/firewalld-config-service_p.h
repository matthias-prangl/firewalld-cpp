#pragma once

#include "firewalld_config_service_interface.h"

namespace firewalld::config {

class ServiceDBus;

class ServiceDBusPrivate : public QObject {
  Q_OBJECT

public:
  explicit ServiceDBusPrivate(const QString &path, ServiceDBus *q);
  ~ServiceDBusPrivate() override;
  void init();

  bool builtin;
  bool isDefault;
  QString filename;
  QString name;
  QString path;
  QString uni;

  OrgFedoraprojectFirewallD1ConfigServiceInterface serviceIface_;
  ServiceDBus *q_ptr;

  Q_DECLARE_PUBLIC(ServiceDBus)

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
