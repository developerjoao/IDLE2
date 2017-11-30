#include "../include/warrior.h"

    //constructors and destructors.
    Warrior::Warrior(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Warrior::Warrior() = default;
    Warrior::~Warrior() = default;

    //Getters
    int const& Warrior::getLabel() const{
      return this->label;
    }

    //Functions
    void Warrior::lvl_up(){

    }

    int Warrior::attack(int monsterDef){
      if (rand()%100>=95){
          return (this->equiped[0].getAtk()+getDex())*2;
      }else{
        if(this->getDex()>monsterDef){
          return this->equiped[0].getAtk()+getStr();
        }else{
          return 0;
        }
      } 
    }