
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
		
	public:
		//constructor
		
		Date(int = 1901, int = 1, int = 1);
		Date(Date&);

		~Date();
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();
		
		//other
		bool lessThan(Date& d);
		void print();
		int day;
	private:
		//functions
		int getMaxDay();	
	
		//variables
		
		int month;
		int year;

};
#endif
