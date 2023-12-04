#ifndef TOWER_H
#define TOWER_H


#include "Entity.h"


class Tower: public Entity {
    public:
        Tower(const Location& loc = *(new Location(0, 0)));
        static void resetID();  
        virtual void print() const;    
    private:
        static const char code;
        static int nextID; 
};
#endif
