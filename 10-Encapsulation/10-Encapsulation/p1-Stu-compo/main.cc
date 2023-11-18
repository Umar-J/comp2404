#include <iostream>
using namespace std;

#include "Student.h"

#include <iostream>

int main()
{
  cout<<"Making a new Student..."<<endl;
  Student stu("100567899", "Stu", "CS", 9.0f, 123, "Main", "Ottawa", "ON");
  
  stu.getAddress().setNumber(321);

  // const Address* ad = &(stu.getAddress());

  //ad->setNumber(321);
  cout<<"Printing pointer address:"<<endl;

  //ad->print();

  //Address ad(123, "Main", "Ottawa", "ON");

  // Student joe;
  // joe.setName("Joe");

  //stu->print();

  //Student joe = *stu;  //initializer syntax - invokes the copy constructor
  
  //joe.print();

  

  //cout<<"printing Joe..."<<endl;
  //joe.print();


  return 0;
}
