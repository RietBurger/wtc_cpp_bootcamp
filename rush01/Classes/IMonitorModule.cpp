#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() {
    //
}

IMonitorModule::~IMonitorModule() {
    //
}

std::string IMonitorModule::getHostNameModule() const {
    return this->_HostNameModule;
}

std::string IMonitorModule::getRamModule() const {
    return this->_RamModule;
}

std::string IMonitorModule::getNetworkModule() const {
    return this->_NetworkModule;
}

std::string IMonitorModule::getOSModule() const {
    return this->_OSModule;
}

std::string IMonitorModule::getCPUModule() const {
    return this->_CPUModule;
}
std::string IMonitorModule::getDateTimeModule() const {
    return this->_DateTimeModule;
}
