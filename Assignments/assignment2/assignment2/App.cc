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
    return this->title == title;
}

void App::print() const {
    cout<<"Title:       "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<endl;
}

void App::printWithIcon() const{
    cout<<"Title:       "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<icon<<endl;
}
