#include "iostream"
#include "Character.h"
#include "battle.h"

using namespace std;

int main(){
    string name;
    int health,damage;   
    //fighter
    cout<<"Enter name, health, damage for Fighter character"<<endl; 
    cin>>name>>health>>damage; //input for fighter
    Character fighter = Character(name, health, damage);

    //orc
    cout<<"Enter name, health, damage for Orc character"<<endl;
    cin>>name>>health>>damage; //input for orc
    Character orc = Character(name, health, damage);
    
    fighter.print();
    orc.print();
    
    Gondor::fight(fighter,orc);
    fighter.print();
    orc.print();

    Mordor::fight(fighter, orc);
    fighter.print();
    orc.print();
} 