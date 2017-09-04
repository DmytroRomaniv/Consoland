#include "Functions.h"

using namespace std;

int move(Map map, Hero character)
{
	int enter;
	int i;
	int j;
	bool exit;

	enter = 0;
	i = (map.get_i_size() / 2) - 1;
	j = (map.get_j_size() / 2) - 1;
	exit = false;
	
	map.set_object(i, j, 'A');
	while (enter != 27)
	{
		map.print();
		map.replace('A', nthng);
		enter = _getch();
		switch (enter)
		{
		case 72:
			if (map.get_object(i - 1, j) == enm)
			{
				character=fight(character);
				if (character.HP <= 0)
				{
					death();
					return 0;
				}
			}
			if (map.get_object(i - 1, j) != obj)
			{
				i--;
				if (map.get_object(i, j) == ex)
				{
					exit = true;
				}
			}
			break;
		case 75:
			if (map.get_object(i, j - 1) == enm)
			{
				character = fight(character);
				if (character.HP <= 0)
				{
					death();
					return 0;
				}
			}
			if (map.get_object(i, j - 1) != obj)
			{
				j--;
				if (map.get_object(i, j) == ex)
				{
					exit = true;
				}
			}
			break;
		case 77:
			if (map.get_object(i, j + 1) == enm)
			{
				character = fight(character);
				if (character.HP <= 0)
				{
					death();
					return 0;
				}
			}
			if (map.get_object(i, j + 1) != obj)
			{
				j++;
				if (map.get_object(i, j) == ex)
				{
					exit = true;
				}
			}
			break;
		case 80:
			if (map.get_object(i + 1, j) == enm)
			{
				character = fight(character);
				if (character.HP <= 0)
				{
					death();
					return 0;
				}
			}
			if (map.get_object(i + 1, j) != obj)
			{
				i++;
				if (map.get_object(i, j) == ex)
				{
					exit = true;
				}
			}
		default:
			break;
		}
		map.set_object(i, j, 'A');
		if (exit)
		{
			map.gen(10, 20);
			exit = false;

			i = (map.get_i_size() / 2) - 1;
			j = (map.get_j_size() / 2) - 1;
			map.set_object(i, j, 'A');
		}
		CLS;
	}
}

Hero fight(Hero main)
{
	int enter;
	int option;
	Mob enemy(5, 0, 2);
	Hero character(main);
	int enemy_move;
	int hero_move;
	int dodge_chance;

	option = 0;

	CLS;
	fight_options(0, enemy, character);

	while (character.HP > 0 && enemy.HP > 0)
	{
		enter = 0;
		while (enter != 13)
		{
			hero_move = enter;
			enter = _getch();
			switch (enter)
			{
			case 77: //right arrow
				option++;
				if (option == 6)
				{
					option = 0;
				}
				break;
			case 75: //left arrow
				option--;
				if (option == -1)
				{
					option = 5;
				}
				break;
			default:
				break;
			}
			CLS;
			fight_options(option, enemy, character);
		}
		enemy_move = random(4) - 1;
		switch (option)
		{
		case 0:
			switch (enemy_move)
			{
			case 0:
				break;
			case 1:
				character.HP -= enemy.Damage;
				break;
			case 2:
				enemy.HP -= character.Damage / 2;
				break;
			case 3:
				dodge_chance = random(100);
				if (dodge_chance % 2 == 0)
				{
					enemy.HP -= character.Damage;
				}
				break;
			}
			break;
		case 1: //charge
			switch (enemy_move)
			{
			case 0:
				enemy.HP -= character.Damage;
				break;
			case 1:
				character.HP = character.HP - enemy.Damage;
				enemy.HP = enemy.HP - character.Damage;
				break;
			case 2:
				enemy.HP -= character.Damage / 2;
				//stan
				break;
			case 3:
				dodge_chance = random(100);
				if (dodge_chance % 2 == 0)
				{
					enemy.HP -= character.Damage;
				}
				break;
			}
			break;
		case 2: //block
			switch (enemy_move)
			{
			case 0:
				character.HP -= enemy.Damage / 2;
				break;
			case 1:
				character.HP -= enemy.Damage / 2;
				//stan;
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		case 3: //dodge
			switch (enemy_move)
			{
			case 0:
				dodge_chance = random(100);
				if (dodge_chance % 2 == 0)
				{
					character.HP -= enemy.Damage;
				}
				break;
			case 1:
				character.HP -= enemy.Damage / 2;
				break;
			case 2:
				break;
			case 3:
				break;
				break;
			}
		case 4:
			//inventory
			break;
		case 5:
			//run away
			break;
		default:
			break;
		}
		CLS;
		fight_options(option, enemy, character);
	}
	return character;
}

Map exit_option(Map level)
{
	CLS;
	cout << "New Level!\n";
	system("pause");
	Map a;
	a.gen(10, 20);
	return a;
}

void start()
{
	Map small_map;
	small_map.gen(10, 20);
	Hero main(5, 5, 2);
	move(small_map, main);
}