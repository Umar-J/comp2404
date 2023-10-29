
#ifndef APPARRAY_H
#define APPARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "App.h"
#include "defs.h"

using namespace std;

class AppArray {
		
	public:
		//constructor
		AppArray();
		
		//destructor
		~AppArray();
		
		//other
		bool add(App*);
		App* get(int) const;
		App* get(const string&) const;
		App* remove(const string& title);
		App* remove(int);
		int size() const;
		bool isFull() const;
		void print() const;
	
	private:
		int numApps;
		App** apps;
};
#endif
