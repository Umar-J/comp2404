#include "AppMarket.h"

// cout message if somethbing fails

void AppMarket::addApp(const string &title, const string &description, const string &icon)
{
    App* toAdd = new App(title, description, icon);
    if(!arrayOfApps.add(toAdd)){//added pointer - so it takes care of the memory
        cout<<"error, could not add app"<<endl;
    }
}

void AppMarket::deleteApp(int index)
{
    App* goner = arrayOfApps.remove(index); // will get null if fails
    if(goner!= NULL){
        delete goner;
    }else{
        cout<<"error, could not remove app"<<endl;
    }
}

App *AppMarket::getApp(int index) const
{
    if (arrayOfApps.get(index) != nullptr){
        return arrayOfApps.get(index);
    }else{
        cout<<"App does not exist there!"<<endl;
        return nullptr;
    }
    return nullptr;
}
void AppMarket::printApps() const
{
    //if(arrayOfDevices.size > 0);
    arrayOfApps.print();   
} 

void AppMarket::printAppDetails(int index) const
{
    App* toPrint = getApp(index);
    if (toPrint != nullptr){
        toPrint->printWithIcon();
    }
}