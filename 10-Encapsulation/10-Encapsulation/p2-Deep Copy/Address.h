#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
  public:
    Address(int=0, string="", string="", string="");
    ~Address();
    void print();

  private:
    int    number;
    string street;
    string city;
    string province;
};

#endif
