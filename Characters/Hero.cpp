#include "Hero.h"

Hero::Hero()
{
	Mob();
	//Inventory = 0;
}

Hero::Hero(const Hero &character)
{
	HP = character.HP;
	MP = character.MP;
	Damage = character.Damage;
}

Hero::Hero(int Hero_HP, int Hero_MP, int Dmg)
{
	HP = Hero_HP;
	MP = Hero_MP;
	Damage = Dmg;
}

void Hero::set_HP(int New_HP)
{
	HP = New_HP;
}