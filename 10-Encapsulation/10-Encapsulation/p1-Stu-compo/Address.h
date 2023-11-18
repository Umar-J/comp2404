#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
  public:
    Address(int=0, string="", string="", string="");
    ~Address();
    void print();
    void setNumber(int num){number = num;}

  private:
    int    number;
    string street;
    string city;
    string province;
};

#endif
