#include "Map.h"

Map::Map()
{
	this->i_size = NULL;
	this->j_size = NULL;
}

Map::Map(Map& map)
{
	this->i_size = map.i_size;
	this->j_size = map.j_size;
	this->matrix = map.matrix;
}

void Map::gen(int i, int j)
{
	this->i_size = i;
	this->j_size = j;
	this->matrix = new char*[i_size];
	for (int i = 0; i < i_size; i++)
	{
		matrix[i] = new char[j_size];
	}
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			/*if (i == 0 || i == i_size - 1)
			{
			matrix[i][j] = '-';
			}
			else if (j == 0 || j == j_size - 1)
			{
			matrix[i][j] = '|';
			}*/
			if (i == 0 || i == i_size - 1 || j == 0 || j == j_size - 1)
			{
				matrix[i][j] = obj;
			}
			else
			{
				matrix[i][j] = nthng;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		int rd_i, rd_j;

		rd_i = random(i_size - 2);
		rd_j = random(j_size - 2);
		matrix[rd_i][rd_j] = enm;
	}
	for (int i = 0; i < 20; i++)
	{
		int rd_i, rd_j;
		
		rd_i = random(i_size - 2);
		rd_j = random(j_size - 2);
		matrix[rd_i][rd_j] = obj;
	}
	gen_exit();
}

void Map::set_object(int i, int j, char object)
{
	this->matrix[i][j] = object;
}

int Map::get_i_size()
{
	return this->i_size;
}

int Map::get_j_size()
{
	return this->j_size;
}

char Map::get_object(int i, int j)
{
	return this->matrix[i][j];
}

void Map::print()
{
	for (int i = 0; i < this->i_size; i++)
	{
		for (int j = 0; j < this->j_size; j++)
		{
			cout << this->matrix[i][j];
		}
		cout << endl;
	}
}

void Map::replace(char object, char new_object)
{
	for (int i = 0; i < this->i_size; i++)
	{
		for (int j = 0; j < this->j_size; j++)
		{
			if (this->matrix[i][j] == object)
			{
				this->matrix[i][j] = new_object;
				break;
			}
		}
	}
}

void Map::gen_exit()
{
	int exit_i, exit_j;
	int side;

	side = random(4);
	switch (side)
	{
	case 1:
		exit_i = 0;
		exit_j = random(j_size - 2);

		this->matrix[exit_i][exit_j] = ex;
		this->matrix[exit_i + 1][exit_j] = nthng;

		break;
	case 2:
		exit_i = i_size - 1;
		exit_j = random(j_size - 2);

		this->matrix[exit_i][exit_j] = ex;
		this->matrix[exit_i - 1][exit_j] = nthng;

		break;
	case 3:
		exit_i = random(i_size - 2);
		exit_j = 0;

		this->matrix[exit_i][exit_j] = ex;
		this->matrix[exit_i][exit_j + 1] = nthng;

		break;
	default:
		exit_i = random(i_size - 2);
		exit_j = j_size - 1;

		this->matrix[exit_i][exit_j] = ex;
		this->matrix[exit_i][exit_j - 1] = nthng;

		break;
	}
}

void Map::new_level()
{
	for (int i = 0; i < i_size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = new char*[i_size];
	for (int i = 0; i < i_size; i++)
	{
		matrix[i]=new char[j_size];
	}
	gen(10, 10);
}

Map::~Map()
{
	if (matrix)
	{
		for (int i = 0; i < i_size; i++)
		{
			matrix[i] = nullptr;
		}
		matrix = nullptr;
	}
}