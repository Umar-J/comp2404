#ifndef APP_H
#define APP_H

#include <string>
#include <iostream>

using namespace std;

class App{
    public:
        App(const string& title, const string& description, const string& icon);
        App();
        App(const App&);
        App(App& cApp); //shouldnt be here
        //App(App*);
        string getTitle(){return title;};
        bool equals(const string& title);
        void print();
        void printWithIcon();
        

    private:
        string title;
        string description;
        string icon;
};




#endif