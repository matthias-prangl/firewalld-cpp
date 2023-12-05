#!/bin/bash

# generate xml interfaces for all FirewallD objects
# remove Introspectable and Properties elements from xml
# generate sdbus-c++ headers from xml

declare -A objects
objects["firewalld"]="/org/fedoraproject/FirewallD1"
objects["firewalld-config"]="/org/fedoraproject/FirewallD1/config"
objects["firewalld-config-helper"]="/org/fedoraproject/FirewallD1/config/helper/0"
objects["firewalld-config-icmptype"]="/org/fedoraproject/FirewallD1/config/icmptype/0"
objects["firewalld-config-ipset"]="/org/fedoraproject/FirewallD1/config/ipset/0"
objects["firewalld-config-policy"]="/org/fedoraproject/FirewallD1/config/policy/0"
objects["firewalld-config-service"]="/org/fedoraproject/FirewallD1/config/service/0"
objects["firewalld-config-zone"]="/org/fedoraproject/FirewallD1/config/zone/0"

for key in "${!objects[@]}"; do
    busctl introspect org.fedoraproject.FirewallD1 "${objects[$key]}" --xml-interface > xml/"$key".xml
    xmlstarlet ed -L -d "//interface[@name=\"org.freedesktop.DBus.Introspectable\"]" -d "//interface[@name=\"org.freedesktop.DBus.Properties\"]" xml/"$key".xml
    if [ "$key" = "firewalld" ]; then
        xmlstarlet ed -L -d "//interface[@name=\"org.fedoraproject.FirewallD1.direct\"]" xml/"$key".xml
    elif [ "$key" = "firewalld-config" ]; then
        xmlstarlet ed -L -d "//interface[@name=\"org.fedoraproject.FirewallD1.config.direct\"]" xml/"$key".xml
    fi
done

echo "XML interfaces generated. Generate Qt DBus Proxy Interface with:"
echo "    qdbusxml2cpp-qt6 <xml-interface>.xml -p <interface-name>"
echo "This will most likely fail due to Qt not being able to resolve non-trivial DBus data types."
echo "Enhance the XML interfaces with annotations until the generation succeeds."
echo "Remove deprecated members according to https://firewalld.org/documentation/man-pages/firewalld.dbus.html"
