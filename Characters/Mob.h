#pragma once
#include "../Utility/Header.h"

using namespace std;

struct Mob
{
	string Name;
	int HP;
	int MP;
	int Damage;
public:
	Mob();
	Mob(string New_Name);
	Mob(int Hero_HP, int Hero_MP, int Hero_Dmg);
	Mob(char symbol);
	
};