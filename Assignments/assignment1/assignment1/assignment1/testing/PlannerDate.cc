#include "PlannerDate.h"

PlannerDate::PlannerDate(Date & idate){
    this->date = idate;
    numEvents = 0;
}

PlannerDate::~PlannerDate(){
    for (int i =0;i<numEvents;i++){
        delete(events[i]);    
    }
}

bool PlannerDate::equals(Date& d){
    return(d.equals(this->date));
}

bool PlannerDate::equals(PlannerDate & p){
    return (this->date.equals(p.date));
}

bool PlannerDate::lessThan(Date & d){
    // if this date is less than argument
    return (this->date.lessThan(d));
}

bool PlannerDate::lessThan(PlannerDate & p){
    return (this->date.lessThan(p.date));
}
bool PlannerDate::addEvent(string title, string description, int startTime, int duration) { 
    // Add the new event in sorted order
    if (numEvents < MAX_EVENTS) {
        Event* newEvent = new Event(title, description, startTime, duration); //if this static then get delted at end of functionX
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
    
    return false;
}



bool PlannerDate::hasEvent(string title){
    for (int i = 0; i < numEvents; i++){
        if (events[i]->getTitle() == title){
            return true;
        }
    }return false;
}

bool PlannerDate::hasConflict(){
    // check all events if they have conflict tureturn true
    for (int i=0; i < numEvents - 1; i++){
            for (int j=i+1; j < numEvents; j++){
                if (events[i]->conflictsWith(*events[j])){
                    return true;
                }
            }
        }return false;
}

void PlannerDate::print(){
    cout<< "Printing the Planner"<<endl;
    date.print();
    for (int i = 0; i < numEvents; i++){
         this->events[i]->print();
    }
}