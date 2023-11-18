#include <iostream>
using namespace std;

#include "Student.h"


int main()
{
  Student ben("100567899", "Obi-wan", "CS", 9.0f);
  Student joe;

  joe.setName("Joe");

  ben.print();
  joe.print();

  
  return 0;
}
