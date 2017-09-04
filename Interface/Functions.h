#pragma once
#include "../Utility/Header.h"
#include "../Structure/Map.h"
#include "../Interface/Print.h"
#include "Mini_Games.h"

//Move character;
int move(Map map, Hero character);

//Cubes
Hero fight(Hero main);

//End of the level;
Map exit_option(Map level);

//Start game;
void start();