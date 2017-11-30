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
      this->setNext_lvl(2*this->getNext_lvl());
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setStr(this->getStr()+this->getLvl()*1);
      this->setHp(this->getHp()+this->getLvl()*5);
    }

    int Warrior::attack(){
      if (rand()%100>=95){
        std::cout << "CRITICAL HIT!!!" << std::endl;
        return (getStr())*1.5;
      }else{
        return getStr();
      }
    }