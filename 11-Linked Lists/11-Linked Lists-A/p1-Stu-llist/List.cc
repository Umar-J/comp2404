#include <iostream>
#include <string>
using namespace std;

#include "List.h"

List::List():head(nullptr) {}


List::~List(){
   cout<<"In List dtor"<<endl;
   Node* curr = head;
   Node* prev;

   while(curr!= nullptr){
      prev = curr;
      curr = curr->next;
      delete prev;
   }
  
}

//add in sorted order by name
bool List::add(Student* stu){
   if (head == nullptr){
      Node* node = new Node;
      node->next = nullptr;
      node->data = stu;
      head = node;
      return true;
   }

   Node* curr = head;
   Node* prev = nullptr;

   while(curr!=nullptr){
      if (stu->lessThan(*curr->data)){
         break;
      }
      prev = curr;
      curr = curr->next;
   }

   Node* newNode = new Node;
   newNode->data = stu;
   if (prev == nullptr){
      newNode->next = head;
      head = newNode;
      return true;
   }
   prev->next = newNode;
   newNode->next = curr;


   return true;
}

Student* List::remove(string name){

   if (head == nullptr)return nullptr;
   Node* curr = head;
   Node* prev = nullptr;

   while(curr != nullptr){
      if (curr->data->equals(name)){
         break;
      }
      prev = curr;
      curr= curr->next;
   }


   if (curr == nullptr){
      return nullptr;
   }

   if (prev == nullptr){
      head = head->next;
   }else{
      prev->next = curr->next;
   }

   Student* goner = curr->data;
   delete curr;

   return goner;
}

// Student* List::get(const string& name){
    
// }

void List::getHonourRoll(List& hr) const{
   Node* curr = head;

   while(curr!=nullptr){
      if (curr->data->isHonourRoll()){
         hr.add(curr->data);
      }
      curr = curr->next;
   }
}

bool List::isEmpty() const
{
   return false;
}

void List::print() const
{

   cout<<"Printing List of Students: "<<endl;
   Node* curr = head;

   while(curr!=nullptr){
      curr->data->print();
      curr = curr->next;
   }
   cout<<"Bye!"<<endl;
}
