
#include "Control.h"
#include "DeviceManager.h"
#include <limits>
#include <vector>

using namespace std;
#define NUM_DEVICES 4
#define NUM_OS 5
extern const  string DEVICETYPE[NUM_DEVICES];
extern const  string OS[NUM_OS];
extern const string deviceNames[5];
extern int deviceType[5];
extern int os[5];
extern const string appTitles[10];
extern const string descriptions[10];
extern const string icons[10];



void Control::launch(){

    vector<string> menu ={
        "Print apps",
        "Print devices",
        "Print device apps",
        "Add apps to device", 
        "Delete app",
        "Delete device",
        "Clone device"
    };

    initApps();
    initDevices();
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printApps(); break;
            case 2: printDevices(); break;
            case 3: printDeviceDetails(); break;
            case 4: addAppsToDevice(); break;
            case 5: deleteApp(); break;
            case 6: deleteDevice(); break;
            case 7: cloneDevice(); break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void Control::initApps(){
    cout<<"Initializing apps..."<<endl;
    for (int i = 0; i < 10; ++i){
        appMarket.addApp(appTitles[i], descriptions[i], icons[i]);
    }
    cout<<"Apps initialized!"<<endl;
}

void Control::initDevices(){
    cout<<"Initializing devices..."<<endl;
    for (int i = 0; i < 5; ++i){
        deviceManager.addDevice(deviceNames[i], DEVICETYPE[deviceType[i]], OS[os[i]]);
    }
    cout<<"Devices initialized!"<<endl;
}

void Control::printApps(){
    cout<<"Printing apps..."<<endl;
    appMarket.printApps();
    cout<<"Apps printed!"<<endl;
}

void Control::printDevices(){
    cout<<"Printing devices..."<<endl;
    deviceManager.printDevices();
    cout<<"Devices printed!"<<endl;
}

void Control::printAppDetails(){
    printApps();
    int index;
    view.getNumber(index);
    cout<<"Printing app details..."<<endl;
    appMarket.printAppDetails(index);
}

void Control::printDeviceDetails(){
    printDevices();
    int index;
    view.getNumber(index);
    cout << "Printing device details..." << endl;
    Device* printAppsOf = deviceManager.getDevice(index);
    if(printAppsOf) printAppsOf->printWithApps();       
}

void Control::addAppsToDevice(){
    int deviceNum;
    int appCount;
    cout<<"Choose device to install on: "<<endl;
    printDevices();
    Device* addAppsTo = nullptr; 
    while(addAppsTo == nullptr){
        view.getNumber(deviceNum);
        addAppsTo = deviceManager.getDevice(deviceNum);  
    }
    cout<<"how many apps are you installing? "<<endl;
    view.getNumber(appCount);
    printApps();
    for (int i=0; i<appCount; i++){
        int appIndex;
        view.getNumber(appIndex);
        cout << "Adding app to device... " << endl;
        App* toAdd = nullptr;
        toAdd = appMarket.getApp(appIndex);
        while(toAdd == nullptr){
            view.getNumber(appIndex);
            toAdd = appMarket.getApp(appIndex);
        }
        deviceManager.getDevice(deviceNum)->addApp(*toAdd);
    }
}

void Control::deleteApp(){
    printApps();
    int appIndex;
    view.getNumber(appIndex);
    cout << "Deleting app..." << endl;
    appMarket.deleteApp(appIndex);
}

void Control::deleteDevice(){
    int deviceNumber;
    printDevices();
    view.getNumber(deviceNumber);
    cout<<"Deleting device... "<<endl;
    deviceManager.deleteDevice(deviceNumber);
}

void Control::cloneDevice(){
    int cloneFrom;
    int cloneTo;
    printDevices();
    cout<<"Enter index to clone from:"<<endl;
    view.getNumber(cloneFrom);
    printDevices();
    cout<<"Enter index to clone to:"<<endl;
    view.getNumber(cloneTo);
    cout << "Cloning apps" << endl;
    deviceManager.cloneDevice(cloneTo, cloneFrom);
}

#define NUM_DEVICES 4
#define NUM_OS 5

const  string DEVICETYPE[NUM_DEVICES]={"PHONE", "TABLET", "LAPTOP", "DESKTOP"};
const  string OS[NUM_OS] = {"ANDROID", "IOS", "WINDOWS", "MACOS", "LINUX"};

const string deviceNames[5] = {"My Android Phone", "My iPad", "My Gaming Desktop", "My Macbook", "My Linux Laptop"};
int deviceType[5] = {0, 1, 3, 2, 2};
int os[5] = {0, 1, 2, 3, 4};

const string appTitles[10] = {"Flappy Birds", "Office", "Snapchat", "VirtualBox", "Grand Theft Auto 6", "Messages", "Netflix", "iTunes", "Photoshop", "Gimp"};
const string descriptions[10] = {"Video game", "Office apps", "Social Media", "OS Virtualization", "AAA Game", "Text Messages", "Video Streaming", "Music and Video Streaming", "Editing", "Image Editing"};

const string icons[10] = {
R"(
  ___
 / _ \
| (_) |
 \___/
)",

R"(
  ,--.
 /  0 \
|   .  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

R"(
  ____
 /  00\
|    0 |
|______|
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"
};
