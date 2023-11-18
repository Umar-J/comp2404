#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g, int n, string s, string c, string p): number(s1), name(s2), majorPgm(s3), gpa(g), homeAddr(n,s,c,p)
{ 
  cout<<"-- Student ctor:  "<<name<<endl;}
 

Student::Student(Student& stu): number(stu.number),  name(stu.name), majorPgm(stu.majorPgm), gpa(stu.gpa), homeAddr(stu.homeAddr){
  //add code here
  //homeAddr = new Address(*stu.homeAddr);
  cout<<"-- Student copy constructor:  "<<name<<endl;

}

Student::~Student()
{ 
  cout<<"-- Student dtor:  "<<name <<endl;
}

string Student::getName()       { return name; }
void Student::setName(string n) { name = n; }

void Student::print() 
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "        << setw(10) << majorPgm << "   GPA:"
                     <<fixed << setprecision(2)<< setw(5) << right << gpa << endl;
  homeAddr.print();
}

