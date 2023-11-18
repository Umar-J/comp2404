#include <iostream>
using namespace std;

#include "Student.h"


int main()
{
  Student* stu = new Student("100567899", "Stu", "CS", 9.0f, 123, "Main", "Ottawa", "ON");

  //Address ad(123, "Main", "Ottawa", "ON");

  // Student joe;
  // joe.setName("Joe");

  stu->print();

  Student joe = *stu;  //initializer syntax - invokes the copy constructor
  
  //joe.print();

  cout<<"Deleting stu..."<<endl;

  delete stu;

  //cout<<"printing Joe..."<<endl;
  joe.print();


  return 0;
}
