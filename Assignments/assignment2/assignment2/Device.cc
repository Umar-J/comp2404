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
    if(appArray.isFull())return false;
    App* copy = new App(app); ;//add copy (coz if u delete the app from marketplace u shold still have in device)
    return appArray.add(copy);
}

bool Device::deleteApp(const string& title)
{
    App* toRemove = appArray.remove(title);
    if(toRemove){ //since apparray doesnt deallocate
        delete toRemove;
        return true;
    }
    return false;
}

void Device::cloneApps(const Device& other){
    for (int i = 0; i < appArray.size(); ++i) {
        App* dApp = appArray.remove(0);
        delete dApp;
    }
    for (int i = 0; i < other.appArray.size(); ++i) {
        App* appToCopy = other.appArray.get(i);
        if (appToCopy) {
            App* appCopy = new App(*appToCopy); 
            addApp(*appCopy);
            delete appCopy; //delete it since in the addappfuncitno it makes a copy of it anyways so this wont be used after the clone apps function
                            //ie: the memory address made at this new ^ is not the one being stored in the array
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
        appArray.get(i)->printWithIcon();
        
    }

}
