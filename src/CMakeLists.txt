set(DBUS_INTERFACE_SOURCES
  dbus/firewalld_config_helper_interface.cpp
  dbus/firewalld_config_icmptype_interface.cpp
  dbus/firewalld_config_interface.cpp
  dbus/firewalld_config_ipset_interface.cpp
  dbus/firewalld_config_policy_interface.cpp
  dbus/firewalld_config_service_interface.cpp
  dbus/firewalld_config_zone_interface.cpp
  dbus/firewalld_interface.cpp
)

set(SOURCES
  firewalld-config.cpp
  firewalld-config_p.h
  firewalld-config-zone.cpp
  include/firewalld-config.h
  include/firewalld-config-zone.h
  firewalld-config-zone_p.h
)

add_library(firewalld-cpp SHARED ${SOURCES} ${DBUS_INTERFACE_SOURCES})
set_target_properties(firewalld-cpp PROPERTIES AUTOMOC TRUE)
target_include_directories(firewalld-cpp PUBLIC include dbus)
target_link_libraries(firewalld-cpp PRIVATE Qt5::DBus Qt5::Core)
