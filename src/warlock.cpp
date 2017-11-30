#include "../include/warlock.h"

    //constructors and destructors.
    Warlock::Warlock(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Warlock::~Warlock() = default;
    
    //Getters
    int const& Warlock::getLabel() const{
      return this->label;
    }

    //Functions
    void Warlock::lvl_up(){

    }

    int Warlock::attack(int monsterDef){
        return (this->equiped[0].getAtk()+getWis())/2;
    }
