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
        void addCellPhone(const string& number, const Location&);
        void addTower(const Location&);
        void routeMessage(const Message&);
        void moveCellPhone(const string& id, const Location&);
        bool getMessageHistory(const string& id, const List** messages);
        void getMessagesWith(const string& id1, const string& id2, List& outputList);
        void resetIds() const;
        void printTowers() const;
        void printCellPhones() const;
        CellPhone *getCellphone(const string &id, vector<CellPhone *> cellPhones);
        Tower* getTower(const string& id, vector<Tower*> towers);
        Tower *getClosestTower(const Location &) const;

    private:
        //use composition
        // ds for towers
        vector <Tower*> towers; 
        // ds for cellphones
        vector <CellPhone*> cellPhones;
        
    
};
#endif