  #include "../include/equips.h"

    //Constructors and Destructor
    Equip::Equip() = default;
    
    Equip::Equip(std::string name,int atk,int def){
      this->name = name;
      this->atk = atk;
      this->def = def;
    }

    Equip::~Equip() = default;
  
  //Getters
  std::string const& Equip::getName() const{
      return this->name;
  }
  int const& Equip::getAtk() const{
      return this->atk;
  }

  int const& Equip::getDef() const{
      return this->def;
  }

  //Setters
  void Equip::setName(std::string name){
      this->name = name;
  }

  void Equip::setAtk(int atk){
    this->atk = atk;
  }

  void Equip::setDef(int def){
    this->def = def;
  }