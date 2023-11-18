#include <iostream>
using namespace std;

#include "Array.h"

Array::Array(){
    size = 0;
    elements = new Student*[MAX_ARR];
}

/*
    Usually bad form to delete elements in a Array,
    since they may be stored in more than one Array.
    However, we can delete the Array.
*/
Array::~Array(){
    delete [] elements;
}

bool Array::add(Student* s){
    if (size >= MAX_ARR)return false;

    for (int i = size; i > 0 ; --i){
        if (s->lessThan(*elements[i-1])){
            //keep making space by copying elements
            //one location to the right
            elements[i]=elements[i-1];
        }else{
            //we have found where s should go
            elements[i] = s;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    elements[0] = s;
    ++size;
    return true;
    
}


Student* Array::get(const string& name){
    for (int i = 0; i < size; ++i){
        if (elements[i]->equals(name)){
            return elements[i];
        }
    }
    return nullptr;
}

Student* Array::get(int index){
    if (index < 0 || index >= size) return nullptr;
    return elements[index];
}

Student* Array::remove(const string& name){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (!elements[index]->equals(name)&& index < size){
        ++index;
    }

    //did we fall off the end of the Array?
    if (index == size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    Student *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return stu;

}

void Array::removeUpTo(const string& name, Array& arr){
    //find index of the first Student who comes after name
    int index = 0;

    while (elements[index]->equals(name)&& index < size){
        //return them to the calling function
        arr.add(elements[index++]);
    }

    //the number of items to remove
    int toRemove = index;
    while(index < size){
        elements[index - toRemove] = elements[index];
        ++index;
    }

    size -= toRemove;
}

void Array::getHonourRoll(Array& hr) const{
    for (int i = 0; i < size; ++i){
        if (elements[i]->isHonourRoll()){
            hr.add(elements[i]);
        }
    }
}

void Array::print() const
{
  cout << endl << endl << "Students:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}