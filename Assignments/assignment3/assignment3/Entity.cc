#include "Entity.h"

Entity::Entity(const char& character, int num, const Location& location) {
    id = character + to_string(num);
    this->location = location;
}
//make dtor
Entity::~Entity() {
    //keep deleteing first element until list is empty
    while (messageHistory.getSize() > 0) {
        delete messageHistory.removeFirst();
    }
}
int Entity::getNumMessages() const{
    return messageHistory.getSize();
}
bool Entity::equals(const string& id) const{
    return this->id == id;
}
const Location& Entity::getLocation() const {
    return location;
}
List* Entity::getMessageHistory() const{
    return (List*)&messageHistory;
}
void Entity::print() const{
    cout << "Entity: " << id << endl;
    cout << "Location: ";
    location.print();
    cout<<endl;
    cout << "Number of messages: " << getNumMessages() <<endl;
    
}

void Entity::addMessage(const Message &m){
    //make copy of m and add it to messageHistry
    Message* copy = new Message(m);
    messageHistory.add(copy);

}
