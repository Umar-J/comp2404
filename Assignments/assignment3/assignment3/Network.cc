#include "Network.h"

void Network::addCellPhone(const string& number, const Location& loc ){
    //  create new cell phone                        dereference since new returns pointer
    CellPhone* newCellPhone = new CellPhone(number, loc);
    cellPhones.push_back(newCellPhone); //dynamic memory so free later
}
Network::~Network(){
        // Free memory allocated for CellPhone objects
    for (CellPhone* phone : cellPhones) {
        delete phone; // Delete each dynamically allocated CellPhone
    }
    cellPhones.clear(); // Clear the vector (optional)

        // Free memory allocated for Tower objects
    for (Tower* tower : towers) {
        delete tower; // Delete each dynamically allocated CellPhone
    }
    towers.clear(); // Clear the vector (optional)
}
void Network::addTower(const Location& loc){
    //  create new tower
    Tower* newTower = new Tower(loc);
    towers.push_back(newTower); //dynamic memory so free later
}

void Network::routeMessage(const Message& message){
    //message contain ID of sender and reciever
    string sender = message.getSender();
    string reciever = message.getReciever();
    //find cellphone with sender or reciever (id- the one in entity.h)
    bool flag = true;
    for (CellPhone* phone : cellPhones) {
        //since spec says "if both exist add to both"
        if(phone->equals(sender)){
            //add message to message history of sender and reciever
            phone->addMessage(message);

            if(getClosestTower(phone->getLocation())){//checks null
                getClosestTower(phone->getLocation())->addMessage(message);
            }

            flag = false;
        }
        else if(phone->equals(reciever)){
            //add message to message history of sender and reciever
            phone->addMessage(message);

            if(getClosestTower(phone->getLocation())){//checks null
                getClosestTower(phone->getLocation())->addMessage(message);
            }
            flag = false;
        }
        
    }
    if (flag){
        //no phones exist
        cout<<"Could not find phones"<<endl;
    }
}


Tower *Network::getClosestTower(const Location &loc) const{
    int minDistance = 500;
    Tower* closestTower = nullptr;
    for (Tower* tower : towers) {
        if(tower->getLocation().getDistance(loc)<minDistance){ //gets distance between tower and location
            minDistance = tower->getLocation().getDistance(loc);
            closestTower = tower;
        }
    }
    return closestTower; //check null
}

void Network::moveCellPhone(const string& id, const Location& loc){
    if(getCellphone(id, cellPhones)){//check null
        getCellphone(id, cellPhones)->setLocation(loc);
    }
}

bool Network::getMessageHistory(const string& id, const List** messages){
    if(getCellphone(id, cellPhones)){
        *messages = getCellphone(id, cellPhones)->getMessageHistory();
        return true;
    }else if(getTower(id, towers)){
        *messages = getTower(id, towers)->getMessageHistory();
        return true;
    }else{
        return false;
        }

}
void Network::getMessagesWith(const string& id1, const string& id2, List& outputList){
    //it will add duplicates unfortunately but we dont have to check?????
    for(CellPhone* phone : cellPhones){
        phone->getMessageHistory()->getMessagesWith(id1,id2,outputList);
    }
    for(Tower* tower : towers){
        tower->getMessageHistory()->getMessagesWith(id1,id2,outputList);
    }
}

void Network::resetIds() const{
    CellPhone::resetID();
    Tower::resetID();
}

void Network::printTowers() const{
    for(Tower* tower : towers){
        tower->print();
    }
}

void Network::printCellPhones() const{
    for(CellPhone* phone : cellPhones){
        phone->print();
    }
}






CellPhone* Network::getCellphone(const string& id, vector<CellPhone*> cellPhones){
    // if sender is same then it only returns the same one everytime
    for (CellPhone* phone : cellPhones) {
        if(phone->equals(id)){
            return phone;
        }
    }
    return nullptr;// check null
}
Tower* Network::getTower(const string& id, vector<Tower*> towers){
    for (Tower* tower : towers) {
        if(tower->equals(id)){
            return tower;
        }
    }
    return nullptr;// check null
}