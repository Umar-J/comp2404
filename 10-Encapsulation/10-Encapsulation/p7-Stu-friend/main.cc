#include <iostream>
using namespace std;

#include "Student.h"


void where(Student& stu);

int main()
{
  Student stu("100567899", "Stu", "CS", 9.0f, 123, "Main", "Moncton", "NB");
  Student joe;

  joe.setName("Joe");

  cout<<endl<<"Students:"<<endl;
  stu.print();
  joe.print();

  stu.moveTo("Vancouver", "BC");
  joe.moveTo("Montreal", "QC");

  cout<<endl<<"Students after the move:"<<endl;
  stu.print();
  joe.print();

  cout << endl;
  where(stu);
  where(joe);

  return 0;
}

void where(Student& stu)
{
 cout << "Found address in " << stu.homeAddr.city 
      << ", " << stu.homeAddr.province << endl;
}


