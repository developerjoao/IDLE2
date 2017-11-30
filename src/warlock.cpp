#include "../include/warlock.h"

    //constructors and destructors.
    Warlock::Warlock(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }
    Warlock::Warlock() = default;
    Warlock::~Warlock() = default;
    
    //Getters
    int const& Warlock::getLabel() const{
      return this->label;
    }

    //Functions
    void Warlock::lvl_up(){
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setNext_lvl(2*this->getNext_lvl());
      this->setWis(this->getWis()+this->getLvl()*pow(1.1,this->getLvl()));
      this->setHp(this->getHp()+this->getLvl()*1);
    }

    int Warlock::attack(){
      return (getWis()/2);
    }

  void Warlock::equip(Equip equip_){
    if(equip_.getType().compare("cajado") == 0){
      this->equiped = equip_;
      if(this->equiped.getName() == "Vazio"){
        system("clear");
        return;
      }else if(this->equiped.getName()!= "Vazio"){
        system("clear");
        this->setWis(this->getWis()+equiped.getAtk());
        std::cout << this->equiped.getName() << " foi equipado(a)!" << std::endl;
      }
    } else {
      std::cout << "Nao e possivel equipar!" << std::endl;
    }
  }

  void Warlock::equip(){
    Equip vazio;
    this->equiped = vazio;
  }


  int Warlock::equipPrice(){
    //std::cout << "Desequipado" << std::endl;
    return this->equiped.getPreco();
  }
    
