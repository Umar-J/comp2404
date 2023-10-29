
#ifndef DEVICEARRAY_H
#define DEVICEARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Device.h"
#include "defs.h"

using namespace std;

class DeviceArray {
		
	public:
		//constructor
		DeviceArray();
		
		//destructor
		~DeviceArray();
		
		//other
		bool add(Device*);
		Device* get(int) const;
		Device* get(const string&) const;
		Device* remove(const string& title);
		Device* remove(int);
		int size() const;
		bool isFull() const;
		void print() const;
	
	private:
		int numDevices;
		Device** devices;
};
#endif
