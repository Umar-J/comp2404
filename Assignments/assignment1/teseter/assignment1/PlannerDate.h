#ifndef PLANNERDATE_H
#define PLANNERDATE_H
#include "Date.h"
#include "Event.h"

using namespace std;

#define MAX_EVENTS 12

//plannerdate takes date and event to make a pplanner date
// make planner date from a date and compare planner dates and dates
class PlannerDate{
    public:
    PlannerDate(Date&);
    ~PlannerDate(); //destructor
    bool equals(Date&);
    bool equals(PlannerDate&);
    bool lessThan(Date&);
    bool lessThan(PlannerDate&);
    Date getDate(){return date;};
    bool addEvent(string, string, int, int);
    bool hasEvent(string);
    bool hasConflict();
    void print();



    private:
    Date date;
    Event* events[MAX_EVENTS]; //statically allocated array, holds Date* (date pointers)
    int numEvents =0;

};
#endif