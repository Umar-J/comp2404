#ifndef LIST_H
#define LIST_H

#include <string>
#include "Student.h"

using namespace std;

class List{

    class Node{
        public:
            Student* data;
            Node* next;
    };

    public:
        List();
        ~List();
        bool add(Student*);
        Student* get(const string& name);
        Student* get(int index);
        Student* remove(string name);
        void removeUpTo(const string& name, List& goners);

        // Add all students on the honour roll to hr.
        // This is why we don't delete - students may be in 
        // more than one Array. If we delete automatically,
        // when we delete the honour roll all those students 
        // would be lost.
        void getHonourRoll(List& hr) const;

        void print() const;
    
    private:
        Node* head;

};


#endif

