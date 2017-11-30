#include "../include/warrior.h"

    //constructors and destructors.
    Warrior::Warrior(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
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
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setNext_lvl(2*this->getNext_lvl());
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

    void Warrior::equip(Equip equip_){
      if(equip_.getType().compare("espada") == 0){
        this->equiped = equip_;
        if(this->equiped.getName() == "Vazio"){
          system("clear");
          return;
        }else if(this->equiped.getName()!= "Vazio"){
          system("clear");
          this->setStr(this->getStr()+equiped.getAtk());
          std::cout << this->equiped.getName() << " foi equipado(a)!" << std::endl;
        }
      }
      else {
          std::cout << "Nao e possivel equipar!" << std::endl;
      }
    }

  void Warrior::equip(){
    Equip vazio;
    this->equiped = vazio;
  }


  int Warrior::equipPrice(){
    //std::cout << "Desequipado" << std::endl;
    return this->equiped.getPreco();
  }
