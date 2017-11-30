#include "../include/thief.h"   

    //constructors and destructors.
    Thief::Thief(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, std::vector<Equip> equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }

    Thief::~Thief() = default;
     //Getters
     int const& Thief::getLabel() const{
        return this->label;
     }

    //Functions
    void Thief::lvl_up(){
      this->setNext_lvl(2*this->getNext_lvl());
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setDex(this->getDex()+this->getLvl()*1);
      this->setHp(this->getHp()+this->getLvl()*2);
    }
 int Thief::attack(){
  srand(time(NULL));
      if (rand()%100>=90){
        std::cout << "CRITICAL HIT!!!" << std::endl;
        return (this->getDex())*2.5;
      }
      else{
        return this->getDex();
      }
    }