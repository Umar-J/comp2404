#include "AppMarket.h"

// cout message if somethbing fails

AppMarket::AppMarket(){
    AppArray arrayOfApps;
}

AppMarket::~AppMarket(){
    //since the 'new' heap objects are being added to arrayOfApps.add(toAdd) then remove it form there aswell
    for(int i = 0; i < arrayOfApps.size(); i++){
        App* goner = arrayOfApps.get(i);
        delete goner;
    }
}

bool AppMarket::addApp(const string &title, const string &description, const string &icon){
    App* toAdd = new App(title, description, icon); // makes new app object and adds it to the array of apps
    if (arrayOfApps.add(toAdd)){
        cout << "New app added sucessfully!" << endl;
        return true;
    }
    cout<< "Unable to add new app!" << endl;
    return false;
}

bool AppMarket::deleteApp(int index){
    
    if (arrayOfApps.get(index)){ //if index exitsts
        cout << "App " << arrayOfApps.get(index)->getTitle() << " deleted " << endl;
        delete arrayOfApps.remove(index);
        return true;
    }
    cout << "Could not delete app!" << endl;
    return false; 
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
    cout<<"Apps:"<<endl;
    for (int i = 0; i < arrayOfApps.size(); ++i){
		cout<<i<<": "<<endl;
		arrayOfApps.get(i)->print();
        cout<<endl;
	} 
} 

void AppMarket::printAppDetails(int index) const
{
    arrayOfApps.get(index)->printWithIcon();
}