#include "Support.h"

using namespace std;


template<typename T>
void gen_matrix(T** matrix, int i_size, int j_size)
{
	matrix = new T*[i_size];
	for (int i = 0; i < i_size; i++)
	{
		matrix[i] = new T[j_size];
	}
	return matrix;
}

int random(int max_value)
{
	int number;
	random_device rd_number;
	mt19937 rd(rd_number());
	uniform_int_distribution<> dist(1, max_value);
	number = dist(rd_number);
	return number;
}

void borders(char** matrix, int i_size, int j_size)
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			if (i == 0 || i == i_size - 1)
			{
				matrix[i][j] = (char)205;
			}
			if (j == 0 || j == j_size - 1)
			{
				matrix[i][j] = (char)186;
			}
		}
	}
	matrix[0][0] = (char)201;
	matrix[i_size - 1][0] = (char)200;
	matrix[0][j_size-1] = (char)187;
	matrix[i_size-1][j_size-1] = (char)188;
}