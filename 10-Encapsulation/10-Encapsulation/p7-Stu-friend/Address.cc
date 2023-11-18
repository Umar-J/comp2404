#include <iostream>
using namespace std;
#include <string>

#include "Address.h"


Address::Address(int n, string s, string c, string p) 
{ 
  cout<<"-- Address ctor"<<endl;

  number   = n;
  street   = s;
  city     = c;
  province = p;
}

Address::~Address()
{
  cout<<"-- Address dtor"<<endl;
}

void Address::print() const
{
  cout<<"          Address:  "<<number<<" "<<street<<", "<<city<<", "<<province;
}

