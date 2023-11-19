#ifndef CELLPHONE_H
#define CELLPHONE_H

#include <iostream>
#include <string>

#include "Location.h"
#include "List.h"
#include "Entity.h"

class CellPhone: public Entity {
    public:
        CellPhone(string, const Location&);
        static void resetID();  
        virtual void print() const;    
        void setLocation(const Location&);
        //adds mesage to messages if it has the same id as this(s or r)
        void getMessagesWith(const string& id, List& messages);

    private:
        static const char code;
        static int nextID; 
        string number;
};
#endif
