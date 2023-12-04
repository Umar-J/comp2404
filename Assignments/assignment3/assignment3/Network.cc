#include "Network.h"

void Network::addCellPhone(const string& number, const Location& loc ){
    //  create new cell phone                        dereference since new returns pointer
    CellPhone* newCellPhone = new CellPhone(number, loc);
    cellPhones.push_back(newCellPhone); //dynamic memory so free later
}
Network::~Network(){

    for (CellPhone* phone : cellPhones) {
        delete phone; 
    }
    cellPhones.clear(); 

    for (Tower* tower : towers) {
        delete tower; 
    }
    towers.clear(); 
}
void Network::addTower(const Location& loc){
    //  create new tower
    Tower* newTower = new Tower(loc);
    towers.push_back(newTower); 
}

void Network::routeMessage(const Message& message){
    string sender = message.getSender();
    string reciever = message.getReceiver();
    bool flag = true;
    Tower* senderTower = nullptr;
    Tower* recieverTower = nullptr;
     // if both use same tower then it will only add to one
    for (CellPhone* phone : cellPhones) {
         //since spec says "if both exist add to both"
        if(phone->equals(sender)){
             //add message to message history of sender and reciever
            phone->addMessage(message);

            if(getClosestTower(phone->getLocation())&& getClosestTower(phone->getLocation())!= recieverTower){//checks null
                getClosestTower(phone->getLocation())->addMessage(message);
                senderTower = getClosestTower(phone->getLocation());
            }

            flag = false;
         }
         if(phone->equals(reciever)){
             //add message to message history of sender and reciever
             phone->addMessage(message);
             if(getClosestTower(phone->getLocation()) && getClosestTower(phone->getLocation())!= senderTower){//checks null
                 getClosestTower(phone->getLocation())->addMessage(message);
                recieverTower = getClosestTower(phone->getLocation());
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

bool Network::getMessageHistory(const string& id, const List** messages) const{
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
void Network::getMessagesWith(const string& id1, const string& id2, List& outputList)const{
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

CellPhone* Network::getCellphone(const string& id, vector<CellPhone*> cellPhones)const {
    for (CellPhone* phone : cellPhones) {
        if(phone->equals(id)){
            return phone;
        }
    }
    return nullptr;// check null
}
Tower* Network::getTower(const string& id, vector<Tower*> towers) const{
    for (Tower* tower : towers) {
        if(tower->equals(id)){
            return tower;
        }
    }
    return nullptr;// check null
}