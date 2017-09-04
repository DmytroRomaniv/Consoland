#include "Mini_Games.h"

using namespace std;

bool cubes()
{
	int player_value;
	int bot_value;

	player_value = random(6);
	bot_value = random(6);
	
	CLS;
	print_cube(player_value, bot_value);

	if (player_value >= bot_value)
	{
		cout << "~ You win! ~" << endl;
		system("pause");
		return true;
	}
	else
	{
		cout << (char)197 << " You lose! " << (char)197 << endl;
		system("pause");
		return false;
	}
}

void print_cube(int p_value, int b_value)
{
	char** p_cube;
	char** b_cube;
	
	p_cube = new char*[5];
	b_cube = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		p_cube[i] = new char[9];
		b_cube[i] = new char[9];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			p_cube[i][j] = ' ';
			b_cube[i][j] = ' ';
		}
	}
	borders(p_cube, 5, 9);
	borders(b_cube, 5, 9);

	switch (p_value)
	{
	case 2:
		p_cube[3][2] = 'O';
		p_cube[1][6] = 'O';
		break;
	case 3:
		p_cube[3][2] = 'O';
		p_cube[1][6] = 'O';
		p_cube[2][4] = 'O';
		break;
	case 4:
		p_cube[3][2] = 'O';
		p_cube[1][6] = 'O';
		p_cube[1][2] = 'O';
		p_cube[3][6] = 'O';
		break;
	case 5:
		p_cube[3][2] = 'O';
		p_cube[1][6] = 'O';
		p_cube[1][2] = 'O';
		p_cube[3][6] = 'O';
		p_cube[2][4] = 'O';
		break;
	case 6:
		p_cube[1][2] = 'O';
		p_cube[2][2] = 'O';
		p_cube[3][2] = 'O';
		p_cube[1][6] = 'O';
		p_cube[2][6] = 'O';
		p_cube[3][6] = 'O';
		break;
	default:
		p_cube[2][4] = 'O';
		break;
	}
	
	switch (b_value)
	{
	case 2:
		b_cube[3][2] = 'O';
		b_cube[1][6] = 'O';
		break;
	case 3:
		b_cube[3][2] = 'O';
		b_cube[1][6] = 'O';
		b_cube[2][4] = 'O';
		break;
	case 4:
		b_cube[3][2] = 'O';
		b_cube[1][6] = 'O';
		b_cube[1][2] = 'O';
		b_cube[3][6] = 'O';
		break;
	case 5:
		b_cube[3][2] = 'O';
		b_cube[1][6] = 'O';
		b_cube[1][2] = 'O';
		b_cube[3][6] = 'O';
		b_cube[2][4] = 'O';
		break;
	case 6:
		b_cube[1][2] = 'O';
		b_cube[2][2] = 'O';
		b_cube[3][2] = 'O';
		b_cube[1][6] = 'O';
		b_cube[2][6] = 'O';
		b_cube[3][6] = 'O';
		break;
	default:
		b_cube[2][4] = 'O';
		break;
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << p_cube[i][j];
		}
		cout << "     ";
		for (int j = 0; j < 9; j++)
		{
			cout << b_cube[i][j];
		}

		cout << endl;
	}
}