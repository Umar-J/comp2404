#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"

class Student
{
  friend void where(Student&);

  public:
    Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f,
            int=0, string="", string="", string="");
    ~Student();
    string getName() const;
    void setName(string);
    void print() const;

    void moveTo(const string&, const string&);


  private:
    const string number;
    string  name;
    string  majorPgm;
    float   gpa;
    Address homeAddr;
};

#endif
