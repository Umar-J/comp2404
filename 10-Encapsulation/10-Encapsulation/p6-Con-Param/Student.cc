#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"

Student::Student(): Student("Default","-1"){
  cout<<"Default ctor"<<endl;
}
Student::Student(const string& s1, const string& s2) 
  : number(s1), name(s2)
{ 
  cout<<"-- Student ctor:  "<< s2 <<endl;
}

Student::~Student()
{
  cout<<"-- Student dtor:  "<< name <<endl;
}

string Student::getName() const { return name; }

void Student::setName(string n) { 
  name = n;
}

void Student::print() const
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << endl;
}

