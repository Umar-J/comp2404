#include "CellPhone.h"

int CellPhone::nextID = 0;
const char CellPhone::code = 'T';

CellPhone::CellPhone(string iNumber, Location & iLocation): Entity(code, nextID, iLocation){
    number = iNumber;
    nextID++;
}

void CellPhone::resetID(){
    nextID = 0;
}

void CellPhone::print() const{
    cout << "CellPhone: " << id << endl;
    cout << "Location: ";
    location.print();
    cout<<endl;
    cout << "Number of messages: " << getNumMessages() <<endl;
    cout << "Phone Number: " << number << endl;
}

void CellPhone::setLocation(Location &iLocation){
    location = iLocation;
}

void CellPhone::getMessagesWith(const string& id, List& messages){
    //gets this's messages      gets messeages with id  adds to mesages list (return parameter)
    this->getMessageHistory()->getMessagesWith(id, messages);
}
