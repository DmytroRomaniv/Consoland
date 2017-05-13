#pragma once
#include "Header.h"

using namespace std;

class Map
{
private:
	int** matrix;
	int i_size;
	int j_size;
public:
	Map(int i, int j) : i_size(i), j_size(j)
	{
		matrix = new int*[i_size];
		for (int i = 0; i < i_size; i++)
		{
			matrix[i] = new int[j_size];
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
				if (i == 0 || i == i_size - 1|| j == 0 || j == j_size - 1)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < 20; i++)
		{
			int rand_i, rand_j;
			random_device rd_i;
			random_device rd_j;

			mt19937 r_i(rd_i());
			uniform_int_distribution<> dist(1, i_size-2);
			rand_i = dist(r_i);

			mt19937 r_j(rd_j());
			rand_j = dist(r_j);
			matrix[rand_i][rand_j] = 1;
		}
	}

	void set_object(int i, int j, int object)
	{
		matrix[i][j] = object;
	}

	int get_i_size()
	{
		return i_size;
	}

	int get_j_size()
	{
		return j_size;
	}

	int get_object(int i, int j)
	{
		return matrix[i][j];
	}

	void print()
	{
		for (int i = 0; i < i_size; i++)
		{
			for (int j = 0; j < j_size; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void replace(int object, int new_object)
	{
		for (int i = 0; i < i_size; i++)
		{
			for (int j = 0; j < j_size; j++)
			{
				if (matrix[i][j] == object)
				{
					matrix[i][j] = new_object;
					break;
				}
			}
		}
	}
};