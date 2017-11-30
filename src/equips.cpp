  #include "../include/equips.h"

    //Constructors and Destructor
    Equip::Equip() = default;
    
    Equip::Equip(std::string name,std::string type,int atk, int preco){
      this->name = name;
      this->type = type;
      this->atk = atk;
      this->preco = preco;
    }

    Equip::~Equip() = default;
  
  //Getters
  std::string const& Equip::getName() const{
      return this->name;
  }
  std::string const& Equip::getType() const{
      return this->type;
  }

  int const& Equip::getAtk() const{
      return this->atk;
  }

  int const& Equip::getPreco() const{
      return this->preco;
  }

  //Setters
  void Equip::setName(std::string name){
      this->name = name;
  }

  void Equip::setAtk(int atk){
    this->atk = atk;
  }