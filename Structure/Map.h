#pragma once
#include "../Utility/Header.h"
#include "../Interface/Support.h"

using namespace std;

class Map
{
private:
	char** matrix;
	int i_size;
	int j_size;
public:
	Map();

	Map(Map& map);

	void gen(int i, int j);

	void set_object(int i, int j, char object);

	int get_i_size();

	int get_j_size();

	char get_object(int i, int j);

	void print();

	void replace(char object, char new_object);

	void gen_exit();

	void new_level();

	~Map();
};