#include "Character.h"
#include "iostream"

using namespace std;

Character::Character(const string& iname, int imaxHealth, int idamage){
    this->maxHealth = imaxHealth;
    this->currentHealth = maxHealth;
    this->name = iname; 
    this->damage = idamage;
}
const string Character::getName(){
    return this->name;
}
void Character::takeDamage(int damage){
    this->currentHealth = currentHealth - damage;
    if (currentHealth<0){
        currentHealth = 0;
    }
}
int Character::strike(){
    return this->damage;
}
void Character::print(){
    cout<<"The name is: "<<this->name<<" and the health is: "<<this->currentHealth<<endl;
}