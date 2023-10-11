#include <istream>
#include <string>

#include "HeapArrays.h"
#include "StackArrays.h"
#include "App.h"
#include "defs.h"


bool testStackObjectArray();
bool testStackPointerArray();
bool testHeapObjectArray();
bool testHeapPointerArray();

extern const string icons[12];

int main(){

    int choice = 0;
    cout<<"Enter one of the following options: "<<endl;
    cout<<"0. Test StackArrays::getObjectArray"<<endl;
    cout<<"1. Test StackArrays::getPointerArray"<<endl;
    cout<<"2. Test HeapArrays::getObjectArray"<<endl;
    cout<<"3. Test HeapArrays::getPointerArray"<<endl;
    cin >> choice;
    bool flag = true;
    switch(choice){
      case 0: flag = testStackObjectArray(); break;
      case 1: flag = testStackPointerArray(); break;
      case 2: flag = testHeapObjectArray(); break;
      case 3: flag = testHeapPointerArray(); break;
    }
    
    
    if (flag){
      return 0;
    }else{
      return 1;
    }
  
}

bool testHeapObjectArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      App app(title, "5 stars", icons[i]);
      ha.addApp(app);
  }
  App* app = ha.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    // ha.getAppReference(i).printWithIcon();
    app[i].printWithIcon();
    if (&app[i]!=&ha.getAppReference(i)){
      cout<<"Wrong object returned by getAppReference"<<endl;
      return false;
    }
  }
  return true;
}

bool testHeapPointerArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      App app(title, "5 stars", icons[i]);
      ha.addApp(app);
  }
  App** app = ha.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //ha.getAppPointer(i)->printWithIcon();
    (*app[i]).printWithIcon();
    if (app[i]!=ha.getAppPointer(i)){
      cout<<"Wrong object returned by getAppPointer"<<endl;
      return false;
    }
  }
  return true;
}

bool testStackObjectArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < MAX_ARRAY; ++i){
      cin >> title;
      App app(title, "5 stars", icons[i]);
      sa.addApp(app);
  }
  App* app = sa.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //sa.getAppReference(i).printWithIcon();
    app[i].printWithIcon();
    if (&app[i]!=&sa.getAppReference(i)){
      cout<<"Wrong object returned by getAppReference"<<endl;
      return false;
    }
  }
  return true;
}

bool testStackPointerArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < MAX_ARRAY; ++i){
      cin >> title;
      App app(title, "5 stars", icons[i]);
      sa.addApp(app);
  }
  App** app = sa.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //sa.getAppPointer(i)->printWithIcon();
    (*app[i]).printWithIcon();
    if (app[i]!=sa.getAppPointer(i)){
      cout<<"Wrong object returned by getAppPointer"<<endl;
      return false;
    }
  }
  return true;
}

const string icons[12] = {
R"(picture
  ___
 / _ \
| (_) |
 \___/
)",

R"(picture
  ,--.
 /  0 \
|   .  |
 \___/
)",

R"(picture
  ,--.
 /  0 \
|   |  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

R"(
  ____
 /  00\
|    0 |
|______|
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"
};