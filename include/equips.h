#ifndef __EQUIPS__
#define __EQUIPS__

#include <iostream>
#include <string>

class Equip {
  public:
  
  //Constructors and Destructor
    Equip();
    Equip(std::string,int,int);
    ~Equip();
  
  //Getters
  std::string const& getName() const;
  int const& getAtk() const;
  int const& getDef() const;
  
  //Setters
  void setName(std::string);
  void setAtk(int);
  void setDef(int);
  
  //functions
  //void refine();
  
  private:
    std::string name;
    int atk,
        def;
};

#endif /* EQUIPS */