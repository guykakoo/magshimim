#pragma once
#include <string>
#include "DeviceList.h"  // כולל את Device ו-DevicesList

class User
{
public:
    // מאתחל משתמש חדש
    void init(unsigned int id, const std::string& username, unsigned int age);

    // מנקה את האובייקט (ואת רשימת המכשירים)
    void clear();

    // getters - לא משנות מצב => const
    unsigned int getID() const;
    const std::string& getUserName() const;
    unsigned int getAge() const;

    // מחזיר הפניה לרשימת המכשירים (לא עותק!)
    DevicesList& getDevices();
    const DevicesList& getDevices() const; // גרסה לקריאה בלבד (לא חובה, אבל מומלץ)

    // מוסיף מכשיר לרשימת המכשירים
    void addDevice(const Device& newDevice);

    // מחזיר true אם כל המכשירים במצב "פועל"
    bool checkIfDevicesAreOn() const;

private:
    unsigned int  _id = 0;
    std::string   _username;
    unsigned int  _age = 0;
    DevicesList   _devices;   // הרשימה של המכשירים של המשתמש
};
