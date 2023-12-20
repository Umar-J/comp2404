#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "Tester.h"

using namespace std;

class TestControl {
		
	public:
		int launch();
	
	private:
		int deviceTest();
		int destructorTest();
		int cloneDeviceTest();

		

		Tester tester;
	
};
#endif