#ifndef __CHARACTER__
#define __CHARACTER__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"

class Character {
  public:
  
  //Constructors and Destructor
    Character(std::string,int,int,int,int,int,int,int,int);
    Character();
    ~Character();
  
  //Getters
  virtual int const& getLabel() const;
  std::string const& getName() const;
  int const& getHp() const;
  int const& getStr() const;
  int const& getDex() const;
  int const& getWis() const;
  int const& getExp() const;
  int const& getLvl() const;
  int const& getNext_lvl() const;
  int const& getMoney() const;
  
  //Setters
  void setHp(int);
  void setStr(int);
  void setDex(int);
  void setWis(int);
  void setExp(int);
  void setLvl(int);
  void setNext_lvl(int);
  void setMoney(int);

  //Functions
  void battle();
  void lvl_up();
  int attack();
  
  private:
    std::string name;
    int hp,
        str,
        dex,
        wis,
        agi,
        exp,
        lvl,
        next_lvl,
        money;
};
#endif /* CHARACTER */