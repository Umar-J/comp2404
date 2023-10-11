#include "Event.h"

Event::Event(string ititle, string idescription, int istartTime, int iduration){
    this->title = ititle;
    this->description = idescription;
    
    if(istartTime >= 0 && istartTime <= 23){
        this->startTime = istartTime;
    }else{
        startTime = 0;
    }
    
    if (duration >= 1){
        this->duration = iduration;
    }else{
        this->duration = 1;
    }
}

bool Event::equals(Event& e){
    return (title == e.title);
}

bool Event::lessThan(Event& e){
    //return true if starttime of this is less than e
    return (startTime < e.startTime);
}
bool Event::conflictsWith(Event& e){
    // true if the times overlap
    // starts at 12 and is 2 hrs and other start at 14 and ends in 4 hrs then its ok (false)
    // starts at 12 lasts 2 hrs and other starts at 13 and lasts 1 hr (true)
    //          if this + duration > e.start time, return true
    return((startTime + duration) > e.startTime);
}

void Event::print(){
    cout<<"Title:       "<<title<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Start Time:  "<<startTime<<endl;
    cout<<"Duration:    "<< duration <<endl;

}