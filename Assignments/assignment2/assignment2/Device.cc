#include "Device.h"

Device::Device(string name, string deviceType, string os)
{
    this->name = name;
    this->deviceType = deviceType;
    this->os = os;
    AppArray appArray;
}

Device::~Device()
{
    for (int i = 0; i < appArray.size(); i++){
        App* toDelete = appArray.get(i);
        delete toDelete; 
    }
}

bool Device::addApp(const App app)
{
    if(appArray.isFull()){
        return false;
    }else{
        App* copy = new App(app);
        return appArray.add(copy);
    }
}

bool Device::deleteApp(const string& title)
{
    App* toRemove = appArray.remove(title);
    if(toRemove){
        delete toRemove;
        return true;
    }
    return false;
}

void Device::cloneApps(const Device d)
{
    //clear the thing
  for(int i = 0; i < appArray.size(); ++i) {
        App* toClear = appArray.remove(0); //also clearing the memory
        delete toClear;
  }
    //add apps from device (takes apps from d and puts it tho this)
    for (int i =0; i < d.appArray.size(); i++){
        App* appToCopy = d.appArray.get(i);
        if(appToCopy){
            App* appCopy = new App(*appToCopy);
            addApp(*appCopy); //.add makes copy
            delete(appCopy);
        }

    }
}


void Device::print() const
{
    cout<<"Name:        "<<name<<endl;
    cout<<"Device Type: "<<deviceType<<endl;
    cout<<"OS:          "<<os<<endl;
    cout<<"Apps:        "<<appArray.size()<<endl;
    cout<<endl;
}

void Device::printWithApps()const
{
    print();
    cout<<"Printing apps: "<<endl;
    for (int i =0; i < appArray.size(); i++){
        appArray.get(i)->print();
    }

}
