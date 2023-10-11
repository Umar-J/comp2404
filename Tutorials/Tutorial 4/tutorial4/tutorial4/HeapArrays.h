#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <string>
#include <iostream>
#include "defs.h"
#include "App.h"

using namespace std;

class HeapArrays{
    public:
        HeapArrays();
        ~HeapArrays();
        App* getObjectArray(); 
        App** getPointerArray(); 
        App* getAppPointer(int index);
        App& getAppReference(int index);
        void addApp(App a);
        
    private:
        App* appObjects;// = new App[MAX_ARRAY]; //dynamically allocated (holds array of objects)
        App** appPointers;// = new App*[MAX_ARRAY];//dynamically allocated (holds array of pointers) _- thats y its a *
        int numApps;
};
#endif