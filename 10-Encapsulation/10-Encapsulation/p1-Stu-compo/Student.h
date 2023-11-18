#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"

class Student
{
  public:
    Student(string="000000000", string="Student name", string="General arts", float=0.0f, int=123, string="Street", string="City", string="Province");

    Student(Student&);
    ~Student();

    string getName();
    void setName(string);
    void print();
    Address& getAddress() {return homeAddr;}

  private:
    string  number;
    string  name;
    string  majorPgm;
    float   gpa;
    Address homeAddr;

};

int main(){
  Student* stu = new Student;
}
#endif
