#pragma once
#include "../Utility/Header.h"
#include "Mob.h"

using namespace std;

//TODO: ->Mob;
struct Hero
{
	int HP;
	int MP;
	int Damage;
	//int Inventory;
public:
	Hero();
	Hero(const Hero &character);
	Hero(int Hero_HP, int Hero_MP, int Dmg);
	void set_HP(int New_HP);

};