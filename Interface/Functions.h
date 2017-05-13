#pragma once
#include "Header.h"
#include "Map.h"

void move(Map map)
{

	int enter;
	int i;
	int j;

	enter = 0;
	i = (map.get_i_size() / 2) - 1;
	j = (map.get_j_size() / 2) - 1;

	map.set_object(i, j, 7);
	while (enter != 27)
	{
		map.print();
		map.replace(7, 0);
		enter = _getch();
		switch (enter)
		{
		case 72:
			if (map.get_object(i - 1, j) != 1)
			{
				i--;
			}
			break;
		case 75:
			if (map.get_object(i, j - 1) != 1)
			{
				j--;
			}
			break;
		case 77:
			if (map.get_object(i, j + 1) != 1)
			{
				j++;
			}
			break;
		case 80:
			if (map.get_object(i + 1, j) != 1)
			{
				i++;
			}
		default:
			break;
		}
		map.set_object(i, j, 7);
		CLS;
	}
}
void start()
{
	Map small_map(10, 10);
	move(small_map);

}