#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g, int n, string s, string c, string p): number(s1), name(s2), majorPgm(s3), gpa(g), homeAddr(new Address(n, s, c, p))
{
 
 }
 

Student::Student(Student& stu): number(stu.number),  name(stu.name), majorPgm(stu.majorPgm), gpa(stu.gpa), homeAddr(new Address(*stu.homeAddr)){
  //add code here
  //homeAddr = new Address(*stu.homeAddr);
  cout<<"In student copy constructor"<<endl;

}

Student::~Student()
{ 
  cout<<"-- Student dtor:  "<<name <<endl;
  delete homeAddr;
}

string Student::getName()       { return name; }
void Student::setName(string n) { name = n; }

void Student::print() 
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "        << setw(10) << majorPgm << "   GPA:"
                     <<fixed << setprecision(2)<< setw(5) << right << gpa << "!"<<endl;
  homeAddr->print();
}

