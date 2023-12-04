
/*
 * This file was automatically generated by sdbus-c++-xml2cpp; DO NOT EDIT!
 */

#ifndef __sdbuscpp__include_firewalld_config_helper_h__proxy__H__
#define __sdbuscpp__include_firewalld_config_helper_h__proxy__H__

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

namespace org {
namespace fedoraproject {
namespace FirewallD1 {
namespace config {

class helper_proxy
{
public:
    static constexpr const char* INTERFACE_NAME = "org.fedoraproject.FirewallD1.config.helper";

protected:
    helper_proxy(sdbus::IProxy& proxy)
        : proxy_(proxy)
    {
        proxy_.uponSignal("Updated").onInterface(INTERFACE_NAME).call([this](const std::string& name){ this->onUpdated(name); });
        proxy_.uponSignal("Removed").onInterface(INTERFACE_NAME).call([this](const std::string& name){ this->onRemoved(name); });
        proxy_.uponSignal("Renamed").onInterface(INTERFACE_NAME).call([this](const std::string& name){ this->onRenamed(name); });
    }

    ~helper_proxy() = default;

    virtual void onUpdated(const std::string& name) = 0;
    virtual void onRemoved(const std::string& name) = 0;
    virtual void onRenamed(const std::string& name) = 0;

public:
    sdbus::Struct<std::string, std::string, std::string, std::string, std::string, std::vector<sdbus::Struct<std::string, std::string>>> getSettings()
    {
        sdbus::Struct<std::string, std::string, std::string, std::string, std::string, std::vector<sdbus::Struct<std::string, std::string>>> result;
        proxy_.callMethod("getSettings").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void update(const sdbus::Struct<std::string, std::string, std::string, std::string, std::string, std::vector<sdbus::Struct<std::string, std::string>>>& settings)
    {
        proxy_.callMethod("update").onInterface(INTERFACE_NAME).withArguments(settings);
    }

    void loadDefaults()
    {
        proxy_.callMethod("loadDefaults").onInterface(INTERFACE_NAME);
    }

    void remove()
    {
        proxy_.callMethod("remove").onInterface(INTERFACE_NAME);
    }

    void rename(const std::string& name)
    {
        proxy_.callMethod("rename").onInterface(INTERFACE_NAME).withArguments(name);
    }

    std::string getVersion()
    {
        std::string result;
        proxy_.callMethod("getVersion").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setVersion(const std::string& version)
    {
        proxy_.callMethod("setVersion").onInterface(INTERFACE_NAME).withArguments(version);
    }

    std::string getShort()
    {
        std::string result;
        proxy_.callMethod("getShort").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setShort(const std::string& short_)
    {
        proxy_.callMethod("setShort").onInterface(INTERFACE_NAME).withArguments(short_);
    }

    std::string getDescription()
    {
        std::string result;
        proxy_.callMethod("getDescription").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setDescription(const std::string& description)
    {
        proxy_.callMethod("setDescription").onInterface(INTERFACE_NAME).withArguments(description);
    }

    std::string getFamily()
    {
        std::string result;
        proxy_.callMethod("getFamily").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setFamily(const std::string& ipv)
    {
        proxy_.callMethod("setFamily").onInterface(INTERFACE_NAME).withArguments(ipv);
    }

    bool queryFamily(const std::string& ipv)
    {
        bool result;
        proxy_.callMethod("queryFamily").onInterface(INTERFACE_NAME).withArguments(ipv).storeResultsTo(result);
        return result;
    }

    std::string getModule()
    {
        std::string result;
        proxy_.callMethod("getModule").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setModule(const std::string& module)
    {
        proxy_.callMethod("setModule").onInterface(INTERFACE_NAME).withArguments(module);
    }

    bool queryModule(const std::string& module)
    {
        bool result;
        proxy_.callMethod("queryModule").onInterface(INTERFACE_NAME).withArguments(module).storeResultsTo(result);
        return result;
    }

    std::vector<sdbus::Struct<std::string, std::string>> getPorts()
    {
        std::vector<sdbus::Struct<std::string, std::string>> result;
        proxy_.callMethod("getPorts").onInterface(INTERFACE_NAME).storeResultsTo(result);
        return result;
    }

    void setPorts(const std::vector<sdbus::Struct<std::string, std::string>>& ports)
    {
        proxy_.callMethod("setPorts").onInterface(INTERFACE_NAME).withArguments(ports);
    }

    void addPort(const std::string& port, const std::string& protocol)
    {
        proxy_.callMethod("addPort").onInterface(INTERFACE_NAME).withArguments(port, protocol);
    }

    void removePort(const std::string& port, const std::string& protocol)
    {
        proxy_.callMethod("removePort").onInterface(INTERFACE_NAME).withArguments(port, protocol);
    }

    bool queryPort(const std::string& port, const std::string& protocol)
    {
        bool result;
        proxy_.callMethod("queryPort").onInterface(INTERFACE_NAME).withArguments(port, protocol).storeResultsTo(result);
        return result;
    }

public:
    std::string name()
    {
        return proxy_.getProperty("name").onInterface(INTERFACE_NAME);
    }

    std::string filename()
    {
        return proxy_.getProperty("filename").onInterface(INTERFACE_NAME);
    }

    std::string path()
    {
        return proxy_.getProperty("path").onInterface(INTERFACE_NAME);
    }

    bool default_()
    {
        return proxy_.getProperty("default").onInterface(INTERFACE_NAME);
    }

    bool builtin()
    {
        return proxy_.getProperty("builtin").onInterface(INTERFACE_NAME);
    }

private:
    sdbus::IProxy& proxy_;
};

}}}} // namespaces

#endif
