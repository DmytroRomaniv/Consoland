#pragma once
#include "../Utility/Header.h"

//Generate matrix;
template<typename T>
void gen_matrix(T** matrix, int i_size,int j_size);

//Generate random number;
int random(int max_value);

//Create borders;
void borders(char** matrix, int i_size, int j_size);