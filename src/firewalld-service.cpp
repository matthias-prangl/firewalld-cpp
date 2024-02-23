#include "firewalld-service.h"
#include "generictypes.h"

namespace firewalld {
Service::Service(const QVariantMap serviceSettings) {
  version_ = serviceSettings.value("version").toString();
  name_ = serviceSettings.value("name").toString();
  description_ = serviceSettings.value("description").toString();
  ports_ = serviceSettings.value("ports").value<FWPortList>();
  moduleNames_ = serviceSettings.value("module").toStringList();
  destinations_ = serviceSettings.value("destinations").value<FWStringMap>();
  protocols_ = serviceSettings.value("protocols").toStringList();
  sourcePorts_ = serviceSettings.value("source_ports").value<FWPortList>();
  includes_ = serviceSettings.value("includes").toStringList();
  helpers_ = serviceSettings.value("helpers").toStringList();
}
} // namespace firewalld
