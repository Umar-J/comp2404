#include <iostream>
using namespace std;

#include "Book.h"


int main()
{
  cout << "Next id: " << Book::getNextId() << endl;

  cout<<endl<<"Declaring and initializing books 1 to 4..."<<endl;

  Book b1("Ender's Game", "Orson Scott Card");
  Book b2("Dune", "Frank Herbert");
  Book b3("Foundation", "Isaac Asimov");
  Book b4("Hitch Hiker's Guide to the Galaxy", "Douglas Adams");

  b1.print();
  b2.print();
  b3.print();
  b4.print();

  cout << "Next id: " << Book::getNextId() << endl;
  cout << "Next id: " << b4.getNextId() << endl;

  return 0;
}

