#include "../include/thief.h"   

    //constructors and destructors.
    Thief::Thief(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
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
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setNext_lvl(2*this->getNext_lvl());   
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
  void Thief::equip(Equip equip_){
    if(equip_.getType().compare("adaga") == 0){
      this->equiped = equip_;
      if(this->equiped.getName() == "Vazio"){
        system("clear");
        return;
      }else if(this->equiped.getName()!= "Vazio"){
        system("clear");
        this->setDex(this->getDex()+equiped.getAtk());
        std::cout << this->equiped.getName() << " foi equipado(a)!" << std::endl;
      } 
    }
    else {
      std::cout << "Nao e possivel equipar!" << std::endl; 
    }
  }
  void Thief::equip(){
    Equip vazio;
    this->equiped = vazio;
  }

  int Thief::equipPrice(){
    //std::cout << "Desequipado" << std::endl;
    return this->equiped.getPreco();
  }