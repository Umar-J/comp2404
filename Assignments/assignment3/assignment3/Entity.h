#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Location.h"
#include "List.h"

class Entity {
    public:
        // Constructor
        Entity(const char&, int, const Location&);

        // Destructor
        ~Entity(); 

        List* getMessageHistory() const;
        const Location& getLocation() const;
        int getNumMessages() const;
        bool equals(const string& id) const;
        virtual void print() const;
        void addMessage(const Message& m);

    protected:  
        string id;
        Location location;
    private:
        List messageHistory;
    
};
#endif