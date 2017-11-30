#ifndef __MONSTER__
#define __MONSTER__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Monster {
  public:
  
  //Constructors and Destructor
    Monster();
    Monster(std::string,int,int,int,int,int);
    ~Monster();
  
  //Getters
  std::string const& getMonName() const;
  int const& getMonHp() const;
  int const& getMonAtk() const;
  int const& getMonDef() const;
  int const& getMonExp() const;
  int const& getMonLoot() const;
  
  //Setters
  void setMonName(string, Monster&);
  void setMonHp(int, Monster &current);
  void setMonAtk(int, Monster &current);
  void setMonDef(int, Monster &current);
  void setMonExp(int, Monster &current);
  void setMonLoot(int, Monster &current);
  
  //Funcoes
  void assignMonName(string infoType,int contador,Monster &current);
  void assignMon(int infoType,int contador,Monster &current);
  vector<Monster> loadMonster(vector<Monster> &monsters);
  void ranMonster(Monster &aleatorio);

  private:
    std::string name;
    int hp,
        atk,
        def,
        exp,
        loot;
};



#endif /* MONSTER */
