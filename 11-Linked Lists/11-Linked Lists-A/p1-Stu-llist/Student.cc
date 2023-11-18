#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g) 
  : number(s1), name(s2), majorPgm(s3), gpa(g) { }

Student::~Student() { }

bool Student::lessThan(const Student& stu) const{
  return name < stu.name;
}

bool Student::equals(const string& name) const{
  return this->name == name;
}

bool Student::isHonourRoll() const {
  return gpa >= 10.0;
}


void Student::print() const
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "
                     << setw(15) << majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << gpa << endl;
}

