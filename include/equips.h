#ifndef __EQUIPS__
#define __EQUIPS__

#include <iostream>
#include <string>

class Equip {
  public:
  
  //Constructors and Destructor
    Equip();
    Equip(std::string,std::string,int,int);
    ~Equip();
  
  //Getters
  std::string const& getName() const;
  std::string const& getType() const;
  int const& getAtk() const;
  int const& getPreco() const;

  //Setters
  void setName(std::string);
  void setAtk(int);
  
  private:
    std::string name,
                type;
    int atk,
        preco;

};

#endif /* EQUIPS */