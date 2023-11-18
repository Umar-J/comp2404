#include "Planner.h"


Planner::~Planner(){
    for (int i =0;i<numPlans;i++){
        delete(plans[i]); 
    }
    
}

Planner::Planner(){
    numPlans =0;
}
PlannerDate *Planner::getDate(Date& d){
    //if exists then return
    for (int i =0;i<this->numPlans;i++){
        if (plans[i]->equals(d)){
            return plans[i];
        }
    }
    //else make it
    if (numPlans < MAX_EVENTS){
        PlannerDate* nDate = new PlannerDate(d); //mem leak
        //sort the inserts
        int insertIndex = numPlans;
// Find the correct position to insert the new date in ascending order
    for (int i = 0; i < numPlans; i++) {
        if (nDate->lessThan(*plans[i])) {
            insertIndex = i;
            break;
    }
}

// Shift elements to the right to make space for the new date
    for (int i = numPlans - 1; i >= insertIndex; i--) {
        plans[i + 1] = plans[i];
    }

// Insert the new date at the correct position
    plans[insertIndex] = nDate; //nDate is dynamically allocated (delete FROM THIS INDEX in desctuctor)
    numPlans++;
        return nDate;
    }else{
        cout<< "Error: ran out of space in planner Array"<<endl;
        return nullptr;
    }
}



void Planner::addEvent(string title, string description, Date &date, int startTime, int duration){
    getDate(date)->addEvent(title, description, startTime, duration);
}

void Planner::addDailyEvent(string title, string description, Date &startDate, Date &endDate, int startTime, int duration){

    bool flag = true;
        while (flag){
        if (startDate.equals(endDate)){
            flag = false;
        }
        addEvent(title,description, startDate, startTime, duration);  
        startDate.incDate();

    }
}
void Planner::addWeeklyEvent(string title, string description, Date &startDate, Date &endDate, int startTime, int duration){

    do{
      addEvent(title,description, startDate, startTime, duration);  
      startDate.addDays(7);
    }
    while(startDate.lessThan(endDate));
}

void Planner::printAllDates(){
    for (int i =0;i<this->numPlans;i++){
        plans[i]->print();
    }
}

void Planner::printDate(Date &d){
    for (int i =0;i<this->numPlans;i++){
        if (plans[i]->equals(d)){ // if date equals
            plans[i]->print();              // print it out
            return;
        }
    }
    cout<<"no such date exists"<<endl;
}

void Planner::printDatesInRange(Date &startDate, Date &endDate){
  
    bool flag = true;
    while (flag){
        if (startDate.equals(endDate)){
            flag = false;
        }
        printDate(startDate);
        startDate.incDate();
    }

}

void Planner::printDatesWithEvent(string title){
    for (int i =0;i<this->numPlans;i++){
        // check if PlannerDate has event matching title
        if (plans[i]->hasEvent(title)){
            plans[i]->print();

        }
    }
}

void Planner::printDatesWithConflict(){
    for (int i = 0;i<numPlans; i++){
        // check if PlannerDate has event conflicting stuff
        if (plans[i]->hasConflict()){
            plans[i]->print();
         }
    }
}