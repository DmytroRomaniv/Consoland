#include "Mob.h"

Mob::Mob()
{
	Name = nullptr;
	HP = 0;
	MP = 0;
	Damage = 0;
}

Mob::Mob(string Mob_Name)
{
	Name = Mob_Name;
}

Mob::Mob(int Mob_HP, int Mob_MP, int Mob_Dmg)
{
	HP = Mob_HP;
	MP = Mob_MP;
	Damage = Mob_Dmg;
}

Mob::Mob(char symbol)
{
	switch (symbol)
	{
	case '|':
		HP = 5;
		MP = 0;
		Damage = 1;
		break;
	default:
		break;
	}
}