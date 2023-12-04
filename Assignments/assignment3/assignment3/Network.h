#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "CellPhone.h"
#include "Tower.h"
#include <vector>


class Network {
    public:
        // Constructor
        ~Network();
        void addCellPhone(const string& number, const Location&);
        void addTower(const Location&);
        void routeMessage(const Message&);
        void moveCellPhone(const string& id, const Location&);
        bool getMessageHistory(const string& id, const List** messages) const;
        void getMessagesWith(const string& id1, const string& id2, List& outputList) const;
        void resetIds() const;
        void printTowers() const;
        void printCellPhones() const;


    private:
        // ds for towers
        vector <Tower*> towers; 
        // ds for cellphones
        vector <CellPhone*> cellPhones;
        // helper functions
        Tower* getTower(const string& id, const vector<Tower*> towers) const;
        Tower *getClosestTower(const Location &) const;
        CellPhone *getCellphone(const string &id, const vector<CellPhone *> cellPhones) const;

    
};
#endif