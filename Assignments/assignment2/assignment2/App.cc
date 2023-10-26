#include "App.h"

App::App(const string& title, const string& description, const string& icon){
    this->title = title;
    this->description = description;
    this->icon = icon;
}

App::App(){
    title = "";
    description = "";
    icon = "";
}

bool App::equals(const string& title) const{
    if (this->title == title){return true;}
    return false;
}

void App::print() const {
    cout<<"Title: "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<endl;
}

void App::printWithIcon() const{
    cout<<"Title: "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<icon<<endl;
}
