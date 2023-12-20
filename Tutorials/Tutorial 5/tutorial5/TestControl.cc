
#include "TestControl.h"
#include "Device.h"
#include <limits>

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


int TestControl::launch()
{
    int choice = 0;
    cout<<"0. Add Apps to Device and print test"<<endl;
    cout<<"1. Destructor Test"<<endl;
    cout<<"2. Clone Device Test"<<endl;
    cin >> choice;
    switch (choice)
    {
    case 0:
        return deviceTest();
    case 1:
        return destructorTest();
    case 2:
        return cloneDeviceTest();
    }
    return 0;
}


int TestControl::deviceTest()
{
    Device *devs[2];
    vector<int> rapp, rdev; // random app, random devices
    vector<int>::iterator iapp, idev; // iterators for the vectors

    App* apps[10];

    for (int i = 0; i < 10; ++i){
        apps[i]=new App(appTitles[i], descriptions[i], icons[i]);
    }

    int count = 0;
    tester.ran(rdev, 2, 5);   // choose 2 out of 5 devices
    for (idev = rdev.begin(); idev != rdev.end(); ++idev)
    {
        std::cout << endl
                  << "Adding Device  " << deviceNames[*idev] << endl;
        devs[count] = new Device(deviceNames[*idev], DEVICETYPE[deviceType[*idev]], OS[os[*idev]]);
        rapp.clear();
        tester.ran(rapp, 2, 10); // choose 2 out of 10 apps

        for (iapp = rapp.begin(); iapp != rapp.end(); ++iapp)
        {
            std::cout << "Adding App to Device: " << deviceNames[*idev] << endl;
            devs[count]->addApp(*apps[*iapp]);
        }
        ++count;
    }

    std::cout << endl
              << "Printing devices with apps (should be 2 devices and 2 apps each device):" << endl;

    tester.initCapture();

    for (int i = 0; i < 2; ++i)
    {
        devs[i]->printWithApps();
    }

    tester.endCapture();

    int error = 0;

    tester.find(rdev, deviceNames, error);

    std::cout<<"All device names "<<(error==0?"found":"not found")<<endl;


    error = 0;
    tester.find(rapp, appTitles, error);
    
    std::cout<<"All app titles "<<(error==0?"found":"not found")<<endl;

    std::cout<<"Deleting devices"<<endl;
    for (int i = 0; i < 2; ++i)
    {
        delete devs[i];
    }

    return 0;
}

int TestControl::destructorTest()
{
    App* apps[10];
    const int DEVICES = 2;
    const int APPS = 3;
    vector<int> rapp, rdev; // random app, random devices
    vector<int>::iterator iapp, idev; // iterators for the vectors
    for (int i = 0; i < 10; ++i){
        apps[i]=new App(appTitles[i], descriptions[i], icons[i]);
    }

    Device *devs[DEVICES];
    int count = 0;
    tester.ran(rapp, APPS, 10); // choose APPS out of 10 apps

    tester.ran(rdev, DEVICES, 5);   // choose DEVICES out of 5 devices
    for (idev = rdev.begin(); idev != rdev.end(); ++idev)
    {
        std::cout << endl
                  << "Adding Device  " << deviceNames[rdev[0]] << endl;
        devs[count] = new Device(deviceNames[rdev[0]], DEVICETYPE[deviceType[rdev[0]]], OS[os[rdev[0]]]);

        for (iapp = rapp.begin(); iapp != rapp.end(); ++iapp)
        {
            std::cout << "Adding App to Device: " << deviceNames[rdev[0]] << endl;
            devs[count]->addApp(*apps[*iapp]);
        }
        ++count;
    }
    cout<<"Deleting all apps in App Array"<<endl;
    for (int i = 0; i < 10; ++i)
    {
        delete apps[i];
    }
    cout << "Delete all apps in first device" << endl;
    for (iapp = rapp.begin(); iapp != rapp.end(); ++iapp)
    {
        devs[0]->deleteApp(appTitles[*iapp]);
    }
    // while (devs[0]->numApps()!=0)
    // {
    //     cout<<"Deleting app in TestControl"<<endl;
    //     devs[0]->deleteApp(0);
    // }

    cout << "Destroy all devices" << endl;
    for (int j = 0; j < DEVICES; ++j)
    {
        delete devs[j];
    }

    

    cout << "Destructor test complete" << endl;
    return 0;
}

int TestControl::cloneDeviceTest()
{
    App* apps[10];
    const int DEVICES = 2;
    const int APPS = 3;
    vector<int> rapp, rdev; // random app, random devices
    vector<int>::iterator iapp; // iterators for the vectors
    for (int i = 0; i < 10; ++i){
        apps[i]=new App(appTitles[i], descriptions[i], icons[i]);
    }

    Device *devs[DEVICES];

    tester.ran(rdev, DEVICES, 5);   // choose DEVICES out of 5 devices
    
    std::cout << endl
                << "Adding Device  " << deviceNames[rdev[0]] << endl;
    devs[0] = new Device(deviceNames[rdev[0]], DEVICETYPE[deviceType[rdev[0]]], OS[os[rdev[0]]]);
    std::cout << endl
                << "Adding Device  " << deviceNames[rdev[1]] << endl;
    devs[1] = new Device(deviceNames[rdev[1]], DEVICETYPE[deviceType[rdev[1]]], OS[os[rdev[1]]]);

    cout << "Adding apps to first device" << endl;
    rapp.clear();
    tester.ran(rapp, APPS, 10); // choose APPS out of 10 apps
    rapp.clear();
    for (iapp = rapp.begin(); iapp != rapp.end(); ++iapp)
    {
        std::cout << "Adding App to Device: " << deviceNames[rdev[0]] << endl;
        devs[0]->addApp(*apps[*iapp]);
    }

    cout<<"Apps found in first device: "<<devs[0]->numApps()<<endl;
    cout<<"Apps found in second device: "<<devs[1]->numApps()<<endl;

    cout << "Cloning first device to second device" << endl;
    devs[1]->cloneApps(*devs[0]);

    cout << "Deleting all apps in first device, then deleting device" << endl;

    for (iapp = rapp.begin(); iapp != rapp.end(); ++iapp)
    {
        devs[0]->deleteApp(appTitles[*iapp]);
    }

    cout<<"Apps found in first device: "<<devs[0]->numApps()<<endl;
    cout<<"Apps found in second device: "<<devs[1]->numApps()<<endl;
    delete devs[0];

    cout<<"Deleting all apps in App array"<<endl;

    for (int i = 0; i < 10; ++i)
    {
        delete apps[i];
    }

    cout << "Printing apps in second device" << endl;

    tester.initCapture();
    devs[1]->printWithApps();
    tester.endCapture();

    int error = 0;

    tester.find(rapp, appTitles, error);

    cout << "Deep copy test complete" << endl;
    std::cout<<"All app titles "<<(error==0?"found":"not found")<<endl;

    delete devs[1];
    
    return 0;
}


const  string DEVICETYPE[NUM_DEVICES]={"PHONE", "TABLET", "LAPTOP", "DESKTOP"};
const  string OS[NUM_OS] = {"ANDROID", "IOS", "WINDOWS", "MACOS", "LINUX"};


// random titles
const string deviceNames[5] = {"My Android Phone", "My iPad", "My Gaming Desktop", "My Macbook", "My Linux Laptop"};
int deviceType[5] = {0, 1, 3, 2, 2};
int os[5] = {0, 1, 2, 3, 4};


const string appTitles[10] = {"Flappy Birds", "Office", "Snadevshat", "VirtualBox", "Grand Theft Auto 6", "Messages", "Netflix", "iTunes", "Photoshop", "Gimp"};
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
