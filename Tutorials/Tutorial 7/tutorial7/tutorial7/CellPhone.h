#ifndef CELLPHONE_H
#define CELLPHONE_H

#include <iostream>
#include <string>

#include "Location.h"
#include "List.h"
#include "Entity.h"

class CellPhone: public Entity {
    public:
        CellPhone(string, Location& = Location(0,0));
        void resetID();  
        virtual void print() const;    
        void setLocation(Location&);
        void getMessagesWith(const string& id, List& messages);

    private:
        static const char code;
        static int nextID; 
        string number;
};
#endif
