#ifndef APP_H
#define APP_H

#include <string>
#include <iostream>

using namespace std;

class App{
    public:
        App(const string& title, const string& description, const string& icon);
        App();
        string getTitle() const{return title;};
        bool equals(const string& title) const;
        void print() const;
        void printWithIcon() const;

    private:
        string title;
        string description;
        string icon;
};

#endif