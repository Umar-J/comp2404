#include <iostream>
using namespace std;

#include "Student.h"


int main()
{
  Student stu("100567899", "Stu");
  Student joe;

  joe.setName("Joe");

  stu.print();
  joe.print();

  return 0;
}
