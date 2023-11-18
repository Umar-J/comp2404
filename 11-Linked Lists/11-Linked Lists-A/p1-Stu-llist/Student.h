#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;


class Student
{
  public:
    Student(string, string="Hey you!", string="basket-weaving", float=0.0f);
    ~Student();
    void print() const;
    bool lessThan(const Student&) const;
    bool equals(const string& name) const;
    bool isHonourRoll() const;

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
