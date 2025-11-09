#include "Device.h"


void Device::init(unsigned int id, DeviceType type, const std::string& os)
{
    id_ = id;
    type_ = type;
    os_ = os;
    active_ = true; 
}


unsigned int Device::getID() const
{
    return id_;
}


DeviceType Device::getType() const
{
    return type_;
}


const std::string& Device::getOS() const
{
    return os_;
}


bool Device::isActive() const
{
    return active_;
}


void Device::activate()
{
    active_ = true;
}


void Device::deactivate()
{
    active_ = false;
}
