#include "DeviceManager.h"

// cout message if somethbing fails

bool Devicemanager::addDevice(const string &name, const string &deviceType, const string &os)
{
    Device* toAdd = new Device(name, deviceType, os);
    if(arrayOfDevices.add(toAdd)){//added pointer - so it takes care of the memory
        return true;
    } else{
        cout<<"error, could not add device"<<endl;
        return false;
    }

}

bool Devicemanager::deleteDevice(int index)
{
    Device* goner = arrayOfDevices.remove(index); // will get null if fails

    if(goner!= NULL){
        delete goner;
        return true;
    }else{
        cout<<"error, could not remove device"<<endl;
        //delete goner??????????????????????????????
        return false;
    }
   
}

Device* Devicemanager::getDevice(int index) const
{
    if ( arrayOfDevices.get(index) != nullptr){
        return arrayOfDevices.get(index);
    }else{
        cout<<"device does not exist there!"<<endl;
        return nullptr;
    }

   
}

bool Devicemanager::cloneDevice(int cloneTo, int cloneFrom)
{
    // clone from 1 to 2
    //this.cloneApps(Device) void
    Device * copyTo =  arrayOfDevices.get(cloneTo);
    Device * copyFrom = arrayOfDevices.get(cloneFrom);
    if (copyFrom == nullptr || copyTo == nullptr){
        cout<<"device does not exist there"<<endl;
        return false;
    }else{
        copyTo->cloneApps(*copyFrom);
        return true;
    }

}

void Devicemanager::printDevices() const
{
    //if(arrayOfDevices.size > 0);
    arrayOfDevices.print();   
}

void Devicemanager::printDeviceDetails(int index) const
{
    Device * toPrint = getDevice(index);
    if (toPrint != nullptr){
        toPrint->printWithApps();
    }
}