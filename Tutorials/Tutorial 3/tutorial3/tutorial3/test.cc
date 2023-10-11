#include <iostream>
#include <string>
#include <sstream>

#include "PlannerDate.h"
#include "Event.h"
#include "Date.h"
#include "Tester.h"
#include "defs.h"
#define NUM_EVENTS 4

int basicEventTest();
int testprint();
int testprintOrder();


int main(){

    int choice = 0;
    cout << "0: basicEventTest" << endl;
    cout << "1: testprint" << endl;
    cout << "2: testprintOrder" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout<<endl<<endl;
    switch(choice){
      case 0: return basicEventTest(); 
      case 1: return testprint(); 
      case 2: return testprintOrder();
    }
     
}

string titles[NUM_EVENTS] = {"Tutorial", "Lecture", "Lab", "Assignment"};
string descriptions[NUM_EVENTS] = {"Program C++", "Learn C++", "Ask questions", "Make assignment - no segfaults"};


Tester tester;

int basicEventTest(){
    cout << "Testing Event print" << endl << endl;

    Event e1(titles[0], descriptions[0], 10, 2);

    tester.initCapture();
    e1.print();
    tester.endCapture();

    vector<int> keys = {0};

    int error = 0;

    tester.find(keys,titles, error);

    if (error > 0){
        cout << "Event title: "<<titles[0]<<" not found" << endl;
        return 1;
    }

    tester.find(keys,descriptions, error);

    if (error > 0){
        cout << "Event description: "<<descriptions[0]<<" not found" << endl;
        return 1;
    }

    cout<<endl<<"Event::print test passed" << endl << endl;

    cout <<endl<< "Testing Event::lessThan" << endl << endl;

    Event e2(titles[1], descriptions[1], 8, 2);

    e2.print();
    cout<<endl<<"Should be less than"<<endl<<endl;
    e1.print();

    if (e1.lessThan(e2)||!e2.lessThan(e1)){
        cout << "Event::lessThan failed" << endl;
        return 1;
    }
    cout << "Event::lessThan tests passed" << endl;
    return 0;
}


int testprint(){
    Date d(1,1,2023);
    PlannerDate pd(d);

    cout<<"Testing PlannerDate::equals(Date& d)"<<endl<<endl;

    Date d2(1,1,2023);

    if (!pd.equals(d2)){
        cout << "PlannerDate::equals(Date& d) failed" << endl;
        return 1;
    }

    cout<<"PlannerDate::equals(Date& d) passed"<<endl<<endl;

    cout<<"Testing PlannerDate::lessThan(Date& d)"<<endl<<endl;

    Date d3(1,2,2023);

    if (!pd.lessThan(d3)){
        cout << "PlannerDate::lessThan(Date& d) failed" << endl;
        return 1;
    }

    cout<<"PlannerDate::lessThan(Date& d) passed"<<endl<<endl;

    int startTimes[NUM_EVENTS] = {10, 8, 6, 9};

    cout<<"Testing PlannerDate::addEvent and print"<<endl<<endl;

    for (int i = 0; i < NUM_EVENTS; ++i){
        pd.addEvent(titles[i], descriptions[i], startTimes[i], 2);
    }

    int error = 0;
    tester.initCapture();
    pd.print();
    tester.endCapture();

    cout<<endl<<"Searching output..."<<endl<<endl;

    vector<int> keys = {0, 1, 2, 3};
    tester.find(keys, titles, error);
    if (error>0){
        cout<<"PlannerDate::addEvent failed"<<endl;
        return 1;
    }
    tester.find(keys, descriptions, error);
    if (error>0){
        cout<<"PlannerDate::addEvent failed"<<endl;
        return 1;
    }

    cout<<"PlannerDate::addEvent and print passed"<<endl<<endl;
    return 0;
}

int testprintOrder(){
    int startTimes[NUM_EVENTS] = {10, 8, 6, 9};
    vector<int> order = {2, 1, 3, 0};

    Date d(1,1,2023);
    PlannerDate pd(d);

    cout<<"Testing PlannerDate::addEvent and print in order"<<endl<<endl;

    for (int i = 0; i < NUM_EVENTS; ++i){
        pd.addEvent(titles[i], descriptions[i], startTimes[i], 2);
    }

    int error = 0;
    tester.initCapture();
    pd.print();
    tester.endCapture();

    
    tester.findInOrder(order, titles, error);
    if (error>0){
        cout<<"PlannerDate::addEvent failed"<<endl;
        return 1;
    }
    tester.findInOrder(order, descriptions, error);
    if (error>0){
        cout<<"PlannerDate::addEvent failed"<<endl;
        return 1;
    }

    cout<<"PlannerDate::addEvent and print in order passed"<<endl<<endl;
    return 0;
}   