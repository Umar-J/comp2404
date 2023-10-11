#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <string>
#include <iostream>
#include "defs.h"
#include "App.h"

using namespace std;

class StackArrays{
    public:
        ~StackArrays();
        StackArrays();
        App* getObjectArray();// should return the statically allocated array of App objects.
        App** getPointerArray();// should return the statically allocated array of App pointers
        App* getAppPointer(int index);//: return a pointer to the App stored at index in the array of pointers.
        App& getAppReference(int index);// return a reference to the App stored at index in the array of objects
        void addApp(App a);
        
    private:
        App appObjects[MAX_ARRAY]; //no leaks possible
        App* appPointers[MAX_ARRAY]; //maybe leaks so clear this
        int numApps;
};
#endif