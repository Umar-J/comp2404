
#ifndef DEVICEARRAY_H
#define DEVICEARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "App.h"
#include "defs.h"

using namespace std;

class DeviceArray {
		
	public:
		//constructor
		DeviceArray();
		
		//destructor
		~DeviceArray();
		
		//other
		bool add(App*);
		App* get(int) const;
		App* get(const string&) const;
		App* remove(const string& title);
		App* remove(int);
		int size() const;
		bool isFull() const;
	
	private:
		int numApps;
		App** apps;
};
#endif
