#ifndef __FUNC__
#define __FUNC__
#include "../include/monster.h"
#include "../include/character.h"
#include "../include/equips.h"
#include "../include/warrior.h"
#include "../include/warlock.h"
#include "../include/thief.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void display();
void intro();
void save_game(Character*);
bool game(Character*);

#endif