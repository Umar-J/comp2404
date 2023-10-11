#include "Planner.h"


Planner::~Planner(){
    for (int i =0;i<this->numPlans;i++){
        delete(plans[i]); 
    }
}


Planner::Planner(){
    numPlans = 0;
}

PlannerDate *Planner::getDate(Date& d){
    for (int i =0;i<this->numPlans;i++){
        if (plans[i]->getDate().equals(d)){
            return plans[i];
        }
    }

    if (numPlans < MAX_EVENTS){
        PlannerDate* nDate = new PlannerDate(d);
        //sort the inserts
        int insertIndex = numPlans;
        for (int i = 0; i < numPlans; i++) {
            if (nDate->lessThan(*plans[i])){
                insertIndex = i;
                break;
            }        
        }
        for (int i = numPlans; i > insertIndex; i--) {
            plans[i] = plans[i - 1];
        }
        plans[numPlans] = nDate;
        numPlans++;
        return nDate;
    }else{
        cout<< "Error: ran out of space in planner Array"<<endl;
        return nullptr;
    }
/*

if (numEvents < MAX_EVENTS) {
        Event* newEvent = new Event(title, description, startTime, duration);
  // from start of list check if its lower than, if it is then put it there.
        int insertIndex = numEvents;
        for (int i = 0; i < numEvents; i++) {            
            if (newEvent->lessThan(*(events[i]))) {
                insertIndex = i;
                break;
            }
        }
        
        for (int i = numEvents; i > insertIndex; i--) {
            events[i] = events[i - 1];
        }

        events[insertIndex] = newEvent;
        numEvents++;
        
        return true;
    }






*/











}



void Planner::addEvent(string title, string description, Date &date, int startTime, int duration){
    //Event* nEvent = new Event(title, description, startTime, duration);
    getDate(date)->addEvent(title, description, startTime, duration);
}

void Planner::addDailyEvent(string title, string description, Date &startDate, Date &endDate, int startTime, int duration){
    for(int i = startDate.getDay(); i <= endDate.getDay(); i++){// iteratively makes dates (check edge cases)
        Date* iDate = new Date(startDate.getYear(), startDate.getMonth(), i);
        addEvent(title,description, *iDate, startTime, duration); //checks if date is there, if not then adds and adds the event also



        // plans[numPlans] = new PlannerDate(*iDate);
        // plans[numPlans] ->addEvent(title,  description, startTime, duration);
        // numPlans++;
    }
}
void Planner::addWeeklyEvent(string title, string description, Date &startDate, Date &endDate, int startTime, int duration){
    for(int i = startDate.getDay(); i <= endDate.getDay(); i+=7){// iteratively makes dates (skip by 7) (check edge cases)
        Date* iDate = new Date(startDate.getYear(), startDate.getMonth(), i);
        addEvent(title,description, *iDate, startTime, duration); //checks if date is there, if not then adds and adds the event also
    }
}

void Planner::printAllDates(){
    for (int i =0;i<this->numPlans;i++){
        plans[i]->print();
    }
}

void Planner::printDate(Date &d){
    for (int i =0;i<this->numPlans;i++){
        if (plans[i]->getDate().equals(d)){ // if date equals
            plans[i]->print();              // print it out
            return;
        }
    }
    cout<<"no such date exitst"<<endl;
}

void Planner::printDatesInRange(Date &startDate, Date &endDate){
    Date* iDate = new Date(startDate.getYear(), startDate.getMonth(), startDate.getDay());
    for (int i =startDate.getDay(); i <= endDate.getDay();i++){
        printDate(*iDate);
    }
}

void Planner::printDatesWithEvent(string title){
    for (int i =0;i<this->numPlans;i++){
        // check if PlannerDate has event matching title
        if (plans[i]->hasEvent(title)){
            cout<<plans[i]<<endl;
        }
    }
}

void Planner::printDatesWithConflict(){
    for (int i =0;i<this->numPlans;i++){
        // check if PlannerDate has event conflicting stuff
        if (plans[i]->hasConflict()){
            cout<<plans[i]<<endl;
        }
    }   
}
