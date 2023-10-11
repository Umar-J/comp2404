#include "HeapArrays.h"

HeapArrays::HeapArrays(){
    numApps = 0;
    appObjects = new App[MAX_ARRAY]; //dynamically allocated (holds array of objects)
    appPointers = new App*[MAX_ARRAY];//dynamically allocated (holds array of pointers) _- thats y its a *
}

HeapArrays::~HeapArrays(){
    for (int i =0; i < numApps; i++){
        delete(appPointers[i]); //delete only called on pointers to memory
    }
    delete [] appObjects;
    delete [] appPointers;
}

App *HeapArrays::getObjectArray(){
    //return array of objects
    return appObjects;
}

App **HeapArrays::getPointerArray(){
    return appPointers;
}

App *HeapArrays::getAppPointer(int index){
//if(index > 0 && index < MAX_ARRAY){
    return appPointers[index];
//}
return nullptr;
}

App &HeapArrays::getAppReference(int index){
  //  if(index > 0 || index < MAX_ARRAY){
        return appObjects[index];
    //}
}

void HeapArrays::addApp(App a){
 //   if (numApps < MAX_ARRAY){
    appObjects[numApps] = a;
    appPointers[numApps] = new App(a); //use new since you are adding a pointer to the object not the actual object
    numApps++;
 //   }
}
