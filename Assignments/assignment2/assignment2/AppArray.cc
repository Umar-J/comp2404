
#include "AppArray.h"

AppArray::AppArray(){
	numApps = 0;
	apps = new App*[MAX_ARRAY]; //dynamically allocated array of pointers
}

AppArray::~AppArray(){
	delete [] apps;
}

bool AppArray::add(App* app){
	if (isFull()) return false;
	apps[numApps] = app;
	numApps++;
	return true;
}

App* AppArray::remove(const string& title){
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



//does not free memory

App* AppArray::remove(int i){
	if (i < 0 || i >= numApps) return nullptr;
	App* goner = apps[i];

	while (i < numApps - 1){
		apps[i] = apps[i + 1];
		++i;
	}
	--numApps;
	return goner;
}

App* AppArray::get(const string& title) const{
	for (int i = 0; i < numApps; ++i){
		if (apps[i]->equals(title)){
			return apps[i];
		}
	}
	return nullptr;
}

App* AppArray::get(int i) const {
	if (i < 0 || i >= numApps) return nullptr;
	return apps[i];
}

bool AppArray::isFull() const{
	return numApps >= MAX_ARRAY;
}

int AppArray::size() const{
	return numApps;
	
}
