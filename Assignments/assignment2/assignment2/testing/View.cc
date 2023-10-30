#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "View.h"

void View::menu(vector<string>& menu, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < menu.size(); ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > menu.size()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::getNumber(int& num)
{
  cout << "Please make a selection: ";
  cin >> num;
  while (num < 0) {
    cout << "Please make a selection: ";
    cin >> num;
  }
}






