#ifndef __WARRIOR__
#define __WARRIOR__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

class Warrior : public Character{
  public:    
    //constructors and destructors.
    Warrior(std::string,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    Warrior();
    ~Warrior();
    
    //Getters
   virtual int const& getLabel() const override;

    //Functions
    void lvl_up();
    int attack();
  
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
    int const label = 0;
};

#endif /* WARRIOR */