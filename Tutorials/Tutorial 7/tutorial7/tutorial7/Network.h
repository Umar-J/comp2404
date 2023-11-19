#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "CellPhone.h"
#include "Tower.h"
#include "List.h"
#include <vector>


class Network {
    public:
        // Constructor
        ~Network();
        void addCellPhone(const string& number, Location&);
        void addTower(Location);
        void routeMessage(Message&);
        void moveCellPhone(const string& id, Location&);
        void getMessageHistory(const string& id, const List** messages);
        void getMessagesWith(const string& id1, const string& id2, List& outputList);
        void resetIds() const;
        void printTowers() const;
        void printCellPhones() const;
        Tower* getClosestTower(Location&);


    private:
        //use composition
        // ds for towers
        vector <Tower*> towers; 
        // ds for cellphones
        vector <CellPhone*> cellPhones;
        
    
};
#endif