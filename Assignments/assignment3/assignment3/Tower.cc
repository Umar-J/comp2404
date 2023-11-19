#include "Tower.h"

int Tower::nextID = 1;
const char Tower::code = 'T';

Tower::Tower(const Location & iLocation): Entity(code, nextID, iLocation){
    nextID++;
}

void Tower::resetID(){
    nextID = 1;
}

void Tower::print() const{
    cout << "Tower: " << id << endl;
    cout << "Location: ";
    location.print();
    cout<<endl;
    cout << "Number of messages: " << getNumMessages() <<endl;
}