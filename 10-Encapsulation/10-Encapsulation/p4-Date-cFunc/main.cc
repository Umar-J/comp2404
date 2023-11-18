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
  newYear.print();

  Date d2;
  d2 = d1;
  d2.print();


  return 0;
}
