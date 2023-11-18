#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

using namespace std;

class Student;

class Address
{
  
  friend class Student;
  friend void where(Student&);

  public:
    Address(int=0, string="", string="", string="");
    ~Address();
    void print() const;

  private:
    int    number;
    string street;
    string city;
    string province;
};

#endif
