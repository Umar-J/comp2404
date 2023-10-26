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
    }
}

bool Device::addApp(const App app)
{
    if(appArray.isFull()){
        return false;
    }else{
        return appArray.add(&app);
    }
}

bool Device::deleteApp(const string& title)
{
    if(App* hello = appArray.remove(title)){
        delete hello;
        return true;
    }
    return false;
}

void Device::cloneApps(const Device d)
{
    //clear the thing
  while(appArray.size() > 0) {
    delete appArray.remove(0);
  }
    //add apps from device (takes apps from d and puts it tho this)
    for (int i =0; i < d.appArray.size(); i++){
        appArray.add(d.appArray.get(i));
    }
}


void Device::print() const
{
    cout<<"Name: "<<name<<endl;
    cout<<"Device Type: "<<deviceType<<endl;
    cout<<"OS: "<<os<<endl;
    cout<<"Apps: "<<appArray.size()<<endl;
    cout<<endl;
}

void Device::printWithApps()const
{
    print();
    cout<<"apps are:"<<endl;
    for (int i =0; i < appArray.size(); i++){
        appArray.get(i)->printWithIcon();
    }

}
