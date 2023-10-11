#include "battle.h"
#include "Character.h"

using namespace std;
#include "iostream"

void Gondor::fight(Character& fighter, Character& orc){
    int fighterDamage = fighter.strike() + 1;    //fighter add 1 damage
    int orcDamage = orc.strike()-1;  
    orc.takeDamage(fighterDamage);
    fighter.takeDamage(orcDamage);

    //print damage
    cout<<fighter.getName()<<" hit "<<orc.getName()<<" for "<< fighterDamage << " damage! "<<endl;
    cout<<orc.getName()<<" hit "<<fighter.getName()<<" for "<< orcDamage << " damage! "<<endl;
}
void Mordor::fight(Character& fighter, Character& orc){
    int fighterDamage = fighter.strike() - 1;    //fighter remove 1 damage
    int orcDamage = orc.strike() + 1;  

    fighter.takeDamage(orcDamage);
    orc.takeDamage(fighterDamage);

    //print damage
    cout<<fighter.getName()<<" hit "<<orc.getName()<<" for "<< fighterDamage << " damage! "<<endl;
    cout<<orc.getName()<<" hit "<<fighter.getName()<<" for "<< orcDamage << " damage! "<<endl;

}