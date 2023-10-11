#include "StackArrays.h"

StackArrays::~StackArrays(){
    for(int i = 0; i < numApps; i++){
    //for (App* x :appPointers){
        //delete(x);
        delete(appPointers[i]);
    }
}

StackArrays::StackArrays(){
    numApps = 0;
}

App *StackArrays::getObjectArray(){
    return appObjects;
}

App** StackArrays::getPointerArray(){
    return appPointers;
}

App *StackArrays::getAppPointer(int index){
    // if greater than 0, or less than
    //if(index > 0 && index < MAX_ARRAY){
        App* pApp= appPointers[index];
        return pApp;
  //  }
    return nullptr;
}

App &StackArrays::getAppReference(int index){
    //if(index > 0 && index < MAX_ARRAY){
    return appObjects[index];
    //}
}

void StackArrays::addApp(App a){
    //add to both arrays
    //add at index numApps, numApps++
   // if (numApps < MAX_ARRAY){
    appObjects[numApps] = a;     // = for static array
    appPointers[numApps] = new App(a);   // make copy of app and add pointer to next locatino (copy constructor that i made)
    numApps++; 
  //  }
}
