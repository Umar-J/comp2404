#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Event{
    public:
        Event(string, string, int, int);
        bool equals(Event&);
        bool lessThan(Event&);
        bool conflictsWith(Event& e);
        void print();
        string getTitle(){return this->title;};
    private:
        string title;
        string description;
        int startTime;
        int duration;
        
};  
#endif