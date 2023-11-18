#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g, 
                 int n, string s, string c, string p) 
    : number(s1), name(s2), majorPgm(s3), gpa(g), homeAddr(n,s,c,p) { }

Student::~Student() { }

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }



void Student::moveTo(const string& city, const string& province){
  homeAddr.city = city;
  homeAddr.province = province;
}


void Student::print() const
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "
                     << setw(15) << majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << gpa << endl;
  homeAddr.print();
  cout<<endl;
}

