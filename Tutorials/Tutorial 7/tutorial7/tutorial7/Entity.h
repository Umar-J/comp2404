#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Location.h"
#include "List.h"

class Entity {
    public:
        // Constructor
        Entity(const char&, int, Location&);

        // Destructor
        //~Entity(); //no dynamic memory allocation

        List* getMessageHistory();
        Location& getLocation();
        int getNumMessages() const;
        bool equals(const string& id) const;
        virtual void print() const;

    protected:  
        string id;
        Location location;
    private:
        List messageHistory;
    
};
#endif