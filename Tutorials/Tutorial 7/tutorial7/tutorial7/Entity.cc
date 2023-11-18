#include "Entity.h"

Entity::Entity(const char& character, int num, Location& location) {
    id = character + to_string(num);
    this->location = location;
}
int Entity::getNumMessages() const{
    return messageHistory.getSize();
}
bool Entity::equals(const string& id) const{
    return this->id == id;
}
Location& Entity::getLocation() {
    return location;
}
List* Entity::getMessageHistory() {
    return &messageHistory;
}
void Entity::print() const{
    cout << "Entity: " << id << endl;
    cout << "Location: ";
    location.print();
    cout<<endl;
    cout << "Number of messages: " << getNumMessages() <<endl;
    
}

