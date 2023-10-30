//cout message if somethbing fi
//has multiple devices
#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "DeviceArray.h"
#include "Device.h"


class DeviceManager{
    public:
        DeviceManager();
        ~DeviceManager();
        bool addDevice(const string& name,const string& deviceType, const string& os);
        bool deleteDevice(int index);
        Device* getDevice(int index) const;
        bool cloneDevice(int cloneTo, int cloneFrom);
        void printDevices() const;
        void printDeviceDetails(int index) const;
        
    private:
        DeviceArray arrayOfDevices;

};
#endif
