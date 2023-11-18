#ifndef Array_H
#define Array_H

#define MAX_ARR 64

#include "Student.h"

class Array
{
  public:
    Array();
    ~Array();

    bool add(Student*);
    Student* get(const string& name);
    Student* get(int index);
    Student* remove(const string& name);
    void removeUpTo(const string& name, Array& goners);

    // Add all students on the honour roll to hr.
    // This is why we don't delete - students may be in 
    // more than one Array. If we delete automatically,
    // when we delete the honour roll all those students 
    // would be lost.
    void getHonourRoll(Array& hr) const;
    inline int getSize(){return size;}
    void print() const;
    

  private:
    Student** elements;
    int size;
   
};

#endif

