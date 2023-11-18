#include "DeviceManager.h"

// cout message if somethbing fails

DeviceManager::DeviceManager(){
    DeviceArray arrayOfDevices;
}
DeviceManager::~DeviceManager(){ //since we adding copies of each device, then need to deallocate them
    for (int i=0; i< arrayOfDevices.size(); i++){
        Device* deleteDevice = arrayOfDevices.get(i);
        delete deleteDevice;
    }
}

bool DeviceManager::addDevice(const string &name, const string &deviceType, const string &os){
    
    Device* toAdd = new Device(name, deviceType, os); //makes copy of device, make sure that arrray doesnt make copy of it or else address will be lost
    if(arrayOfDevices.add(toAdd)){//add the pointer, if copy added then this pointer will be dangling (no reference to the potiner)
        return true;
    } else{
        cout<<"error, could not add device"<<endl;
        return false;
    }
}

bool DeviceManager::deleteDevice(int index){
    if(arrayOfDevices.get(index)){
        cout << "Device " << arrayOfDevices.get(index)->getName() << " deleted" << endl;
        Device* deleteDevice = arrayOfDevices.remove(index);
        delete deleteDevice;
        return true;
    }else{
        cout<<"error, could not remove device"<<endl;
        return false;
    }   
}

Device* DeviceManager::getDevice(int index) const
{
    if (arrayOfDevices.get(index)){
        return arrayOfDevices.get(index);
    }else{
        cout<<"device does not exist there!"<<endl;
        return nullptr;
    }

   
}

bool DeviceManager::cloneDevice(int cloneTo, int cloneFrom){
    // clone from 1 to 2
    if (arrayOfDevices.get(cloneFrom) && arrayOfDevices.get(cloneTo)){
        cout << "Neither are null " << endl;
        cout << "Cloning apps " << endl;
        arrayOfDevices.get(cloneTo)->cloneApps(*arrayOfDevices.get(cloneFrom));
        cout << "Device " << arrayOfDevices.get(cloneTo)->getName() <<" cloned" << endl;
        return true;
    }else{
        cout << "Could not find device to clone!" << endl;
        return false;
    }

}

void DeviceManager::printDevices() const
{
    cout << "Devices: " << endl;
    for (int i = 0; i < arrayOfDevices.size(); i++){
        cout << i << ": " << endl;
        arrayOfDevices.get(i)->print();
        cout << endl;
    } 
}

void DeviceManager::printDeviceDetails(int index) const
{
    arrayOfDevices.get(index)->printWithApps();
}