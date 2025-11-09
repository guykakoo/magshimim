#include "User.h"

// מאתחל משתמש חדש
void User::init(unsigned int id, const std::string& username, unsigned int age)
{
    _id = id;
    _username = username;
    _age = age;
    _devices.init(); // להתחיל רשימה ריקה
}

// מנקה את האובייקט (כולל הרשימה)
void User::clear()
{
    _devices.clear();
    _id = 0;
    _username.clear();
    _age = 0;
}

// getters
unsigned int User::getID() const
{
    return _id;
}

const std::string& User::getUserName() const
{
    return _username;
}

unsigned int User::getAge() const
{
    return _age;
}

// הפניה לרשימת המכשירים (לא עותק)
DevicesList& User::getDevices()
{
    return _devices;
}

const DevicesList& User::getDevices() const
{
    return _devices;
}

// הוספת מכשיר לרשימה
void User::addDevice(const Device& newDevice)
{
    _devices.add(newDevice);
}

// true אם כל המכשירים "פועלים"
bool User::checkIfDevicesAreOn() const
{
    // מעבר על הרשימה המקושרת
    DeviceNode* curr = _devices.get_first();
    while (curr != nullptr)
    {
        Device& d = curr->get_data();
        if (!d.isActive())
            return false;

        curr = curr->get_next();
    }
    return true; // אם לא מצאנו מכשיר כבוי - כולם פועלים
}
