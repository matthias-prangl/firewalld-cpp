#!/bin/bash

# generate xml interfaces for all FirewallD objects
# remove Introspectable and Properties elements from xml
# generate sdbus-c++ headers from xml

declare -A objects
objects["firewalld"]="/org/fedoraproject/FirewallD1"
objects["firewalld-config"]="/org/fedoraproject/FirewallD1/config"
objects["firewalld-config-helper"]="/org/fedoraproject/FirewallD1/config/helper/0"
objects["firewalld-config-icmptype"]="/org/fedoraproject/FirewallD1/config/icmptype/0"
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
    sdbus-c++-xml2cpp xml/"$key".xml --proxy=include/"$key".h
done
