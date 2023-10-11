#include "App.h"

App::App(const string& title, const string& description, const string& icon){
    this->title = title;
    this->description = description;
    this->icon = icon;
}

bool App::equals(string title){
    if (this->title == title){return true;}
    return false;
}

void App::print(){
    cout<<title<<endl;
    cout<<description<<endl;
}

void App::printWithIcon(){
    cout<<title<<endl;
    cout<<description<<endl;
    cout<<icon<<endl;
}
