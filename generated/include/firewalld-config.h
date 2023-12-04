
/*
 * This file was automatically generated by sdbus-c++-xml2cpp; DO NOT EDIT!
 */

#ifndef __sdbuscpp__include_firewalld_config_h__proxy__H__
#define __sdbuscpp__include_firewalld_config_h__proxy__H__

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

namespace org {
namespace fedoraproject {
namespace FirewallD1 {
namespace config {

class policies_proxy
{
public:
    static constexpr const char* INTERFACE_NAME = "org.fedoraproject.FirewallD1.config.policies";

protected:
    policies_proxy(sdbus::IProxy& proxy)
        : proxy_(proxy)
    {
        proxy_.uponSignal("LockdownWhitelistUpdated").onInterface(INTERFACE_NAME).call([this](){ this->onLockdownWhitelistUpdated(); });
    }

    ~policies_proxy() = default;

    virtual void onLockdownWhitelistUpdated() = 0;

public:
    sdbus::Struct<std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<int32_t>> getLockdownWhitelist()
    {
        sdbus::Struct<std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<int32_t>> result;
        proxy_.callMethod("getLockdownWhitelist").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setLockdownWhitelist(const sdbus::Struct<std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<int32_t>>& settings)
    {
        proxy_.callMethod("setLockdownWhitelist").onInterface(INTERFACE_NAME).withArguments(settings);
    }

    void addLockdownWhitelistCommand(const std::string& command)
    {
        proxy_.callMethod("addLockdownWhitelistCommand").onInterface(INTERFACE_NAME).withArguments(command);
    }

    void removeLockdownWhitelistCommand(const std::string& command)
    {
        proxy_.callMethod("removeLockdownWhitelistCommand").onInterface(INTERFACE_NAME).withArguments(command);
    }

    bool queryLockdownWhitelistCommand(const std::string& command)
    {
        bool result;
        proxy_.callMethod("queryLockdownWhitelistCommand").onInterface(INTERFACE_NAME).withArguments(command).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getLockdownWhitelistCommands()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getLockdownWhitelistCommands").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void addLockdownWhitelistContext(const std::string& context)
    {
        proxy_.callMethod("addLockdownWhitelistContext").onInterface(INTERFACE_NAME).withArguments(context);
    }

    void removeLockdownWhitelistContext(const std::string& context)
    {
        proxy_.callMethod("removeLockdownWhitelistContext").onInterface(INTERFACE_NAME).withArguments(context);
    }

    bool queryLockdownWhitelistContext(const std::string& context)
    {
        bool result;
        proxy_.callMethod("queryLockdownWhitelistContext").onInterface(INTERFACE_NAME).withArguments(context).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getLockdownWhitelistContexts()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getLockdownWhitelistContexts").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void addLockdownWhitelistUser(const std::string& user)
    {
        proxy_.callMethod("addLockdownWhitelistUser").onInterface(INTERFACE_NAME).withArguments(user);
    }

    void removeLockdownWhitelistUser(const std::string& user)
    {
        proxy_.callMethod("removeLockdownWhitelistUser").onInterface(INTERFACE_NAME).withArguments(user);
    }

    bool queryLockdownWhitelistUser(const std::string& user)
    {
        bool result;
        proxy_.callMethod("queryLockdownWhitelistUser").onInterface(INTERFACE_NAME).withArguments(user).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getLockdownWhitelistUsers()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getLockdownWhitelistUsers").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void addLockdownWhitelistUid(const int32_t& uid)
    {
        proxy_.callMethod("addLockdownWhitelistUid").onInterface(INTERFACE_NAME).withArguments(uid);
    }

    void removeLockdownWhitelistUid(const int32_t& uid)
    {
        proxy_.callMethod("removeLockdownWhitelistUid").onInterface(INTERFACE_NAME).withArguments(uid);
    }

    bool queryLockdownWhitelistUid(const int32_t& uid)
    {
        bool result;
        proxy_.callMethod("queryLockdownWhitelistUid").onInterface(INTERFACE_NAME).withArguments(uid).storeResultsTo(result);
        return result;
    }

    std::vector<int32_t> getLockdownWhitelistUids()
    {
        std::vector<int32_t> result;
        proxy_.callMethod("getLockdownWhitelistUids").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

private:
    sdbus::IProxy& proxy_;
};

}}}} // namespaces

namespace org {
namespace fedoraproject {
namespace FirewallD1 {

class config_proxy
{
public:
    static constexpr const char* INTERFACE_NAME = "org.fedoraproject.FirewallD1.config";

protected:
    config_proxy(sdbus::IProxy& proxy)
        : proxy_(proxy)
    {
        proxy_.uponSignal("IPSetAdded").onInterface(INTERFACE_NAME).call([this](const std::string& ipset){ this->onIPSetAdded(ipset); });
        proxy_.uponSignal("IcmpTypeAdded").onInterface(INTERFACE_NAME).call([this](const std::string& icmptype){ this->onIcmpTypeAdded(icmptype); });
        proxy_.uponSignal("ServiceAdded").onInterface(INTERFACE_NAME).call([this](const std::string& service){ this->onServiceAdded(service); });
        proxy_.uponSignal("ZoneAdded").onInterface(INTERFACE_NAME).call([this](const std::string& zone){ this->onZoneAdded(zone); });
        proxy_.uponSignal("PolicyAdded").onInterface(INTERFACE_NAME).call([this](const std::string& policy){ this->onPolicyAdded(policy); });
        proxy_.uponSignal("HelperAdded").onInterface(INTERFACE_NAME).call([this](const std::string& helper){ this->onHelperAdded(helper); });
    }

    ~config_proxy() = default;

    virtual void onIPSetAdded(const std::string& ipset) = 0;
    virtual void onIcmpTypeAdded(const std::string& icmptype) = 0;
    virtual void onServiceAdded(const std::string& service) = 0;
    virtual void onZoneAdded(const std::string& zone) = 0;
    virtual void onPolicyAdded(const std::string& policy) = 0;
    virtual void onHelperAdded(const std::string& helper) = 0;

public:
    std::vector<sdbus::ObjectPath> listIPSets()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listIPSets").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getIPSetNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getIPSetNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getIPSetByName(const std::string& ipset)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getIPSetByName").onInterface(INTERFACE_NAME).withArguments(ipset).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addIPSet(const std::string& ipset, const sdbus::Struct<std::string, std::string, std::string, std::string, std::map<std::string, std::string>, std::vector<std::string>>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addIPSet").onInterface(INTERFACE_NAME).withArguments(ipset, settings).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::ObjectPath> listIcmpTypes()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listIcmpTypes").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getIcmpTypeNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getIcmpTypeNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getIcmpTypeByName(const std::string& icmptype)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getIcmpTypeByName").onInterface(INTERFACE_NAME).withArguments(icmptype).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addIcmpType(const std::string& icmptype, const sdbus::Struct<std::string, std::string, std::string, std::vector<std::string>>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addIcmpType").onInterface(INTERFACE_NAME).withArguments(icmptype, settings).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::ObjectPath> listServices()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listServices").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getServiceNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getServiceNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getServiceByName(const std::string& service)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getServiceByName").onInterface(INTERFACE_NAME).withArguments(service).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addService(const std::string& service, const sdbus::Struct<std::string, std::string, std::string, std::vector<sdbus::Struct<std::string, std::string>>, std::vector<std::string>, std::map<std::string, std::string>, std::vector<std::string>, std::vector<sdbus::Struct<std::string, std::string>>>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addService").onInterface(INTERFACE_NAME).withArguments(service, settings).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addService2(const std::string& service, const std::map<std::string, sdbus::Variant>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addService2").onInterface(INTERFACE_NAME).withArguments(service, settings).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::ObjectPath> listZones()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listZones").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getZoneNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getZoneNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getZoneByName(const std::string& zone)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getZoneByName").onInterface(INTERFACE_NAME).withArguments(zone).storeResultsTo(result);
        return result;
    }

    std::string getZoneOfInterface(const std::string& iface)
    {
        std::string result;
        proxy_.callMethod("getZoneOfInterface").onInterface(INTERFACE_NAME).withArguments(iface).storeResultsTo(result);
        return result;
    }

    std::string getZoneOfSource(const std::string& source)
    {
        std::string result;
        proxy_.callMethod("getZoneOfSource").onInterface(INTERFACE_NAME).withArguments(source).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addZone(const std::string& zone, const sdbus::Struct<std::string, std::string, std::string, bool, std::string, std::vector<std::string>, std::vector<sdbus::Struct<std::string, std::string>>, std::vector<std::string>, bool, std::vector<sdbus::Struct<std::string, std::string, std::string, std::string>>, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<sdbus::Struct<std::string, std::string>>, bool>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addZone").onInterface(INTERFACE_NAME).withArguments(zone, settings).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addZone2(const std::string& zone, const std::map<std::string, sdbus::Variant>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addZone2").onInterface(INTERFACE_NAME).withArguments(zone, settings).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::ObjectPath> listPolicies()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listPolicies").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getPolicyNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getPolicyNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getPolicyByName(const std::string& policy)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getPolicyByName").onInterface(INTERFACE_NAME).withArguments(policy).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addPolicy(const std::string& policy, const std::map<std::string, sdbus::Variant>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addPolicy").onInterface(INTERFACE_NAME).withArguments(policy, settings).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::ObjectPath> listHelpers()
    {
        std::vector<sdbus::ObjectPath> result;
        proxy_.callMethod("listHelpers").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getHelperNames()
    {
        std::vector<std::string> result;
        proxy_.callMethod("getHelperNames").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath getHelperByName(const std::string& helper)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("getHelperByName").onInterface(INTERFACE_NAME).withArguments(helper).storeResultsTo(result);
        return result;
    }

    sdbus::ObjectPath addHelper(const std::string& helper, const sdbus::Struct<std::string, std::string, std::string, std::string, std::string, std::vector<sdbus::Struct<std::string, std::string>>>& settings)
    {
        sdbus::ObjectPath result;
        proxy_.callMethod("addHelper").onInterface(INTERFACE_NAME).withArguments(helper, settings).storeResultsTo(result);
        return result;
    }

public:
    std::string DefaultZone()
    {
        return proxy_.getProperty("DefaultZone").onInterface(INTERFACE_NAME);
    }

    int32_t MinimalMark()
    {
        return proxy_.getProperty("MinimalMark").onInterface(INTERFACE_NAME);
    }

    void MinimalMark(const int32_t& value)
    {
        proxy_.setProperty("MinimalMark").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string CleanupOnExit()
    {
        return proxy_.getProperty("CleanupOnExit").onInterface(INTERFACE_NAME);
    }

    void CleanupOnExit(const std::string& value)
    {
        proxy_.setProperty("CleanupOnExit").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string CleanupModulesOnExit()
    {
        return proxy_.getProperty("CleanupModulesOnExit").onInterface(INTERFACE_NAME);
    }

    void CleanupModulesOnExit(const std::string& value)
    {
        proxy_.setProperty("CleanupModulesOnExit").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string Lockdown()
    {
        return proxy_.getProperty("Lockdown").onInterface(INTERFACE_NAME);
    }

    void Lockdown(const std::string& value)
    {
        proxy_.setProperty("Lockdown").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string IPv6_rpfilter()
    {
        return proxy_.getProperty("IPv6_rpfilter").onInterface(INTERFACE_NAME);
    }

    void IPv6_rpfilter(const std::string& value)
    {
        proxy_.setProperty("IPv6_rpfilter").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string IndividualCalls()
    {
        return proxy_.getProperty("IndividualCalls").onInterface(INTERFACE_NAME);
    }

    void IndividualCalls(const std::string& value)
    {
        proxy_.setProperty("IndividualCalls").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string LogDenied()
    {
        return proxy_.getProperty("LogDenied").onInterface(INTERFACE_NAME);
    }

    void LogDenied(const std::string& value)
    {
        proxy_.setProperty("LogDenied").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string AutomaticHelpers()
    {
        return proxy_.getProperty("AutomaticHelpers").onInterface(INTERFACE_NAME);
    }

    void AutomaticHelpers(const std::string& value)
    {
        proxy_.setProperty("AutomaticHelpers").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string FirewallBackend()
    {
        return proxy_.getProperty("FirewallBackend").onInterface(INTERFACE_NAME);
    }

    void FirewallBackend(const std::string& value)
    {
        proxy_.setProperty("FirewallBackend").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string FlushAllOnReload()
    {
        return proxy_.getProperty("FlushAllOnReload").onInterface(INTERFACE_NAME);
    }

    void FlushAllOnReload(const std::string& value)
    {
        proxy_.setProperty("FlushAllOnReload").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string RFC3964_IPv4()
    {
        return proxy_.getProperty("RFC3964_IPv4").onInterface(INTERFACE_NAME);
    }

    void RFC3964_IPv4(const std::string& value)
    {
        proxy_.setProperty("RFC3964_IPv4").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string AllowZoneDrifting()
    {
        return proxy_.getProperty("AllowZoneDrifting").onInterface(INTERFACE_NAME);
    }

    void AllowZoneDrifting(const std::string& value)
    {
        proxy_.setProperty("AllowZoneDrifting").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string NftablesFlowtable()
    {
        return proxy_.getProperty("NftablesFlowtable").onInterface(INTERFACE_NAME);
    }

    void NftablesFlowtable(const std::string& value)
    {
        proxy_.setProperty("NftablesFlowtable").onInterface(INTERFACE_NAME).toValue(value);
    }

    std::string NftablesCounters()
    {
        return proxy_.getProperty("NftablesCounters").onInterface(INTERFACE_NAME);
    }

    void NftablesCounters(const std::string& value)
    {
        proxy_.setProperty("NftablesCounters").onInterface(INTERFACE_NAME).toValue(value);
    }

private:
    sdbus::IProxy& proxy_;
};

}}} // namespaces

namespace org {
namespace fedoraproject {
namespace FirewallD1 {
namespace config {

class direct_proxy
{
public:
    static constexpr const char* INTERFACE_NAME = "org.fedoraproject.FirewallD1.config.direct";

protected:
    direct_proxy(sdbus::IProxy& proxy)
        : proxy_(proxy)
    {
        proxy_.uponSignal("Updated").onInterface(INTERFACE_NAME).call([this](){ this->onUpdated(); });
    }

    ~direct_proxy() = default;

    virtual void onUpdated() = 0;

public:
    sdbus::Struct<std::vector<sdbus::Struct<std::string, std::string, std::string>>, std::vector<sdbus::Struct<std::string, std::string, std::string, int32_t, std::vector<std::string>>>, std::vector<sdbus::Struct<std::string, std::vector<std::string>>>> getSettings()
    {
        sdbus::Struct<std::vector<sdbus::Struct<std::string, std::string, std::string>>, std::vector<sdbus::Struct<std::string, std::string, std::string, int32_t, std::vector<std::string>>>, std::vector<sdbus::Struct<std::string, std::vector<std::string>>>> result;
        proxy_.callMethod("getSettings").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void update(const sdbus::Struct<std::vector<sdbus::Struct<std::string, std::string, std::string>>, std::vector<sdbus::Struct<std::string, std::string, std::string, int32_t, std::vector<std::string>>>, std::vector<sdbus::Struct<std::string, std::vector<std::string>>>>& settings)
    {
        proxy_.callMethod("update").onInterface(INTERFACE_NAME).withArguments(settings);
    }

    void addChain(const std::string& ipv, const std::string& table, const std::string& chain)
    {
        proxy_.callMethod("addChain").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain);
    }

    void removeChain(const std::string& ipv, const std::string& table, const std::string& chain)
    {
        proxy_.callMethod("removeChain").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain);
    }

    bool queryChain(const std::string& ipv, const std::string& table, const std::string& chain)
    {
        bool result;
        proxy_.callMethod("queryChain").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain).storeResultsTo(result);
        return result;
    }

    std::vector<std::string> getChains(const std::string& ipv, const std::string& table)
    {
        std::vector<std::string> result;
        proxy_.callMethod("getChains").onInterface(INTERFACE_NAME).withArguments(ipv, table).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::Struct<std::string, std::string, std::string>> getAllChains()
    {
        std::vector<sdbus::Struct<std::string, std::string, std::string>> result;
        proxy_.callMethod("getAllChains").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void addRule(const std::string& ipv, const std::string& table, const std::string& chain, const int32_t& priority, const std::vector<std::string>& args)
    {
        proxy_.callMethod("addRule").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain, priority, args);
    }

    void removeRule(const std::string& ipv, const std::string& table, const std::string& chain, const int32_t& priority, const std::vector<std::string>& args)
    {
        proxy_.callMethod("removeRule").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain, priority, args);
    }

    bool queryRule(const std::string& ipv, const std::string& table, const std::string& chain, const int32_t& priority, const std::vector<std::string>& args)
    {
        bool result;
        proxy_.callMethod("queryRule").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain, priority, args).storeResultsTo(result);
        return result;
    }

    void removeRules(const std::string& ipv, const std::string& table, const std::string& chain)
    {
        proxy_.callMethod("removeRules").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain);
    }

    std::vector<sdbus::Struct<int32_t, std::vector<std::string>>> getRules(const std::string& ipv, const std::string& table, const std::string& chain)
    {
        std::vector<sdbus::Struct<int32_t, std::vector<std::string>>> result;
        proxy_.callMethod("getRules").onInterface(INTERFACE_NAME).withArguments(ipv, table, chain).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::Struct<std::string, std::string, std::string, int32_t, std::vector<std::string>>> getAllRules()
    {
        std::vector<sdbus::Struct<std::string, std::string, std::string, int32_t, std::vector<std::string>>> result;
        proxy_.callMethod("getAllRules").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void addPassthrough(const std::string& ipv, const std::vector<std::string>& args)
    {
        proxy_.callMethod("addPassthrough").onInterface(INTERFACE_NAME).withArguments(ipv, args);
    }

    void removePassthrough(const std::string& ipv, const std::vector<std::string>& args)
    {
        proxy_.callMethod("removePassthrough").onInterface(INTERFACE_NAME).withArguments(ipv, args);
    }

    bool queryPassthrough(const std::string& ipv, const std::vector<std::string>& args)
    {
        bool result;
        proxy_.callMethod("queryPassthrough").onInterface(INTERFACE_NAME).withArguments(ipv, args).storeResultsTo(result);
        return result;
    }

    std::vector<std::vector<std::string>> getPassthroughs(const std::string& ipv)
    {
        std::vector<std::vector<std::string>> result;
        proxy_.callMethod("getPassthroughs").onInterface(INTERFACE_NAME).withArguments(ipv).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::Struct<std::string, std::vector<std::string>>> getAllPassthroughs()
    {
        std::vector<sdbus::Struct<std::string, std::vector<std::string>>> result;
        proxy_.callMethod("getAllPassthroughs").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

private:
    sdbus::IProxy& proxy_;
};

}}}} // namespaces

#endif
