
#include "DeviceArray.h"

DeviceArray::DeviceArray(){
	numApps = 0;
	apps = new App*[MAX_ARRAY];
}


DeviceArray::~DeviceArray(){
	delete [] apps;
}


bool DeviceArray::add(App* app){
	if (isFull()) return false;
	for (int i = size; i > 0 ; --i){
        if (app->lessThan(*elements[i-1])){
            //keep making space by copying elements
            //one location to the right
            elements[i]=elements[i-1];
        }else{
            //we have found where s should go
            elements[i] = app;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    elements[0] = app;
    ++size;
    return true;
}

App* DeviceArray::remove(const string& title){
	int index = 0;

	while (index < numApps){
		if (apps[index]->equals(title)){ break; }
		++index;
	}

	if (index >= numApps) return NULL;

	App* goner;
	goner = apps[index];

	while (index < numApps-1){
		apps[index] = apps[index+1];
		++index;
	}
	--numApps;
	return goner;
}

App* DeviceArray::remove(int i){
	if (i < 0 || i >= numApps) return nullptr;
	App* goner = apps[i];

	while (i < numApps-1){
		apps[i] = apps[i+1];
		++i;
	}
	--numApps;
	return goner;
}

App* DeviceArray::get(const string& title) const{
	for (int i = 0; i < numApps; ++i){
		if (apps[i]->equals(title)){
			return apps[i];
		}
	}
	return nullptr;
}

App* DeviceArray::get(int i) const {
	if (i < 0 || i >= numApps) return nullptr;
	return apps[i];
}

bool DeviceArray::isFull() const{
	return numApps >= MAX_ARRAY;
}

int DeviceArray::size() const{
	return numApps;
}

// void DeviceArray::print() const{
// 	for (int i = 0; i < numApps; ++i){
// 		apps[i]->print();
// 	}
// }
