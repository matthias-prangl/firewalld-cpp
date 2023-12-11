#pragma once

#include <QVariantMap>

namespace firewalld {
QVariantMap retrieveInitialProperties(const QString &ifName,
                                      const QString &path);
};
