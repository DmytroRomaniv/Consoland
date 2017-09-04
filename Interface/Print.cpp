#include "../Utility/Header.h"
#include "../Characters/Hero.h"
#include "../Characters/Mob.h"

using namespace std;

void fight_options(int value, Mob mob, Hero character)
{
	cout << "Enemy: ";
	for(int i=0;i<mob.HP;i++)
	{
		cout << char(219) << " ";
	}
	cout << mob.HP;
	cout << endl << endl;
	cout << "You: ";
	for (int i = 0; i<character.HP; i++)
	{
		cout << char(219) << " ";
	}
	cout << character.HP;
	cout << endl;
	value == 0 ? cout << "-> Attack <-" : cout << "   Attack   ";
	cout << "  ";
	value == 1 ? cout << "-> Charge <-" : cout << "   Charge   ";
	cout << "  ";
	value == 2 ? cout << "-> Block <-" : cout << "   Block   ";
	cout << "  ";
	value == 3 ? cout << "-> Dodge <-" : cout << "   Dodge   ";
	cout << "  ";
	value == 4 ? cout << "-> Inventory <-" : cout << "   Inventory   ";
	cout << "  ";
	value == 5 ? cout << "-> Run <-" : cout << "   Run   ";
}

void death()
{
	CLS;
	cout << "You died!" << endl;
	system("pause");
}