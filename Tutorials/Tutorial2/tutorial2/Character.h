#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character{
    public: 
        Character(const string&, int, int); //constructor
        const string getName();
        void takeDamage(int damage);
        int strike();
        void print();
    private:
        string name;
        int maxHealth, currentHealth, damage;
};

#endif
