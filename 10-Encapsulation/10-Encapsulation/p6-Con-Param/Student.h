#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
  public:
    Student();
    Student(const string&, const string&);
    ~Student();
    string getName() const;
    void setName(string n);
    void print() const;

  private:
    const string number;
    string name;
};

#endif
