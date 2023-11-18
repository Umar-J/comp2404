#include <iostream>
using namespace std;
#include <string>
#include "Date.h"


int main()
{
  Date d1(2013,1,28);
  d1.print();
  cout<<endl;

  const Date newYear(1901, 1, 1);
  //newYear.day = 10;

 // newYear = d1;
 // newYear.print();

  return 0;
}
