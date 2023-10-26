
#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "App.h"
#include "defs.h"
#include "AppArray.h"

using namespace std;

class Device {
		
	public:
		//constructor
		Device(string, string, string);
		
		//destructor
		~Device();
		
		//other
        string getName()const{
            return name;
        }
        bool equals(string cName) const{return cName == name;}
        bool addApp(App app);
        bool deleteApp(string title);
        void cloneApps(Device);
        int numApps() const{return appArray.size();};
        void print() const;
        void printWithApps() const;

	
	private:
		string name;
        string deviceType;
        string os;
        AppArray appArray;
};
#endif
