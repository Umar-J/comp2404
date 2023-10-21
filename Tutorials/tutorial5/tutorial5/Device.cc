#include "Device.h"

Device::Device(string name, string deviceType, string os)
{
    this->name = name;
    this->deviceType = deviceType;
    this->os = os;
}

Device::~Device()
{
    for (int i =0; i < appArray.size(); i++){
        delete (appArray.get(i));
        cout<<"deleting device dtor"<<endl;
    }
}

bool Device::addApp(App app)
{
    if(appArray.isFull()){
        return false;
    }else{
        App *copyApp = new App(app);
        return appArray.add(copyApp);
    }
}

bool Device::deleteApp(string title)
{
    if(appArray.remove(title)){
        return true;
    }
    return false;
}

void Device::cloneApps(Device d)
{
    //clear the thing
    for (int i =0; i < appArray.size(); i++){
        delete (appArray.remove(i));
    }
    //add apps from device
    for (int i =0; i < d.appArray.size(); i++){
        App* toCopy = new App(* (d.appArray.get(i)));
        appArray.add(toCopy);
    }
}

void Device::print()
{
    cout<<name<<endl;
    cout<<deviceType<<endl;
    cout<<os<<endl;
}

void Device::printWithApps()
{
    print();
    cout<<"apps are:"<<endl;
    for (int i =0; i < appArray.size(); i++){
        appArray.get(i)->print();
    }

}
