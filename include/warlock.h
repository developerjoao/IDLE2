#ifndef __WARLOCK__
#define __WARLOCK__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

class Warlock : public Character{
  public:

    //constructors and destructors.
    Warlock(std::string,int,int,int,int,int,int,int,int,std::vector<Equip>,std::list<Equip>);
    // Warlock();
    ~Warlock();
    
    //Getters
    virtual int const& getLabel() const override;
  
    //Functions
    void lvl_up();
    int attack(int);
  private:
    std::vector<Equip> equiped;
    std::list<Equip> inventory;
    int const label = 1;
};

#endif /* WARLOCK */
