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

App::App(const App& cApp){
    this->title = cApp.title;
    this->description = cApp.description;
    this->icon = cApp.icon;
}
App::App(App& cApp){
    this->title = cApp.title;
    this->description = cApp.description;
    this->icon = cApp.icon;
}

// App::App(App *cApp)
// {
//     this->title = cApp->title;
//     this->description = cApp->description;
//     this->icon = "RCMP warns you to not copy anything lol" + cApp->icon;
// }

bool App::equals(const string& title){
    if (this->title == title){return true;}
    return false;
}

void App::print(){
    cout<<"Title: "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<endl;
}

void App::printWithIcon(){
    cout<<"Title: "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<icon<<endl;
}
