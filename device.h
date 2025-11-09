#pragma once
#include <string>

///////////////////////////////////////////////////////////
// Those definitions are used for tests.
// You may add your own, but please do not delete any.
enum DeviceType { PHONE, PC, LAPTOP, TABLET };

#define UbuntuOS  "UbuntuLinux"
#define RedHatOS  "RedHatLinux"
#define MacOS     "MacOS"
#define IOS       "IOS"
#define WINDOWS7  "Windows7"
#define WINDOWS10 "Windows10"
#define WINDOWS11 "Windows11"
#define ANDROID   "Android"
///////////////////////////////////////////////////////////

class Device
{
public:
    
    void init(unsigned int id, DeviceType type, const std::string& os);

    
    unsigned int   getID()   const;
    DeviceType     getType() const;
    const std::string& getOS() const;
    bool           isActive() const;

   
    void activate();
    void deactivate();

private:
    unsigned int  id_ = 0;
    DeviceType    type_ = PHONE;    
    std::string   os_;                 
    bool          active_ = true;     
};
