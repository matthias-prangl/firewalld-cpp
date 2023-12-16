#include "firewalld-internal.h"
#include "firewalld_dbus.h"
#include <QDBusArgument>
#include <QDBusConnection>
#include <QDBusMessage>

QVariantMap firewalld::retrieveInitialProperties(const QString &interfaceName,
                                                 const QString &path) {
  QDBusMessage message = QDBusMessage::createMethodCall(
      dbus::kFirewallDDBusService, path, dbus::kDBusPropertiesIface, "GetAll");
  message << interfaceName;
  QDBusMessage resultMsg = QDBusConnection::systemBus().call(message);
  if (resultMsg.type() == QDBusMessage::ReplyMessage) {
    QVariantMap result;
    QDBusArgument dbusArgument =
        resultMsg.arguments().at(0).value<QDBusArgument>();
    while (!dbusArgument.atEnd()) {
      dbusArgument >> result;
    }
    return result;
  }
  return QVariantMap();
}
