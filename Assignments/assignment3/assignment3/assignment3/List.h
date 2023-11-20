#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "Message.h"

using namespace std;

class List {
    class Node{
        public:
            Message* data;
            Node* next;
    };
    public:
        List();
        ~List();
        bool isEmpty() const;
        int getSize() const;
        Message* removeFirst();
        void add(Message*);
        void print() const;
        void getMessagesWith(const string& id, List& outputList);
        void getMessagesWith(const string& id1,const string& id2,List& outputList);
        void removeMessagesWith(const string& id,List& outputList);


    private:
        Node* head;
        Node* tail;
};
#endif