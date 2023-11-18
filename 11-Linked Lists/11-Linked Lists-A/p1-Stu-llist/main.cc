#include <iostream>
using namespace std;

#include "List.h"
#include "Student.h"


int main()
{
 
  Student* stu = new Student("000000001", "Stu", "Comp sci", 11.0f);

  List comp2404;

  comp2404.print();

  cout<<"Adding stu..."<<endl;
  comp2404.add(stu);
  cout<<"Printing students..."<<endl;
  comp2404.print();
  
    
  cout<<"Adding students..."<<endl;
  comp2404.add(new Student("100333444", "Zeek", "Spanish", 11.5f));

  comp2404.print();
  
  comp2404.add(new Student("100777888", "Harold", "Geography", 7.5f));
 
  cout<<endl;
  comp2404.print();
  cout<<endl;
  comp2404.add(new Student("100555666", "Timmy", "Basket-weaving", 7.5f));
  comp2404.add(new Student("100778999", "Amy", "Math", 10.8f));
  comp2404.add(new Student("100333555", "Betty", "Physics", 11.8f));
  comp2404.add(new Student("100333768", "Dexter", "English", 8.5f));
  
  cout<<"Printing students..."<<endl;
  comp2404.print();

  cout<<"Getting the honour roll..."<<endl;

  List hr;
  comp2404.getHonourRoll(hr);
  hr.print();
  

  // string name  = "Bob";
  // cout<<"Removing "<<name<<" (doesn't exist)..."<<endl;
  // stu = comp2404.remove(name);
  // if (stu!=nullptr){
  //   stu->print();
  //   delete stu;
  // }else{
  //   cout<<name<<" not found"<<endl;
  // }
  
  string name  = "Harold";
  cout<<"Removing "<<name<<"..."<<endl;
  stu = comp2404.remove(name);
  if (stu!=nullptr){
    stu->print();
    delete stu;
  }else{
    cout<<name<<" not found"<<endl;
  }
  cout<<endl<<endl;
  comp2404.print();

  name  = "Zeek";
  cout<<"Removing "<<name<<"..."<<endl;
  stu = comp2404.remove(name);
  if (stu!=nullptr){
    stu->print();
    delete stu;
  }else{
    cout<<name<<" not found"<<endl;
  }
  cout<<endl<<endl;
  comp2404.print();

  string testNames[6]={"Ellie", "Amy", "Timmy", "Stu", "Dexter", "Betty"};
  string tests[6] = {"Remove middle", "Remove first",  "Remove last student", 
  "Remove remaining students", "Remove remaining students", "Remove remaining students"};

  for (int i = 0; i < 6; ++i){
    cout<<"Testing: "<<tests[i]<<endl;
    cout<<"Removing: "<<testNames[i]<<endl;
    stu = comp2404.remove(testNames[i]);
    if (stu != nullptr){
      stu->print();
      delete stu;
    }else{
      cout<<testNames[i]<<" not found"<<endl;
    }
  }

  cout<<endl<<endl<<"Printing empty list"<<endl;
  comp2404.print();
  // hr.print();
  
  return 0;
}

