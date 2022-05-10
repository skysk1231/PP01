#include <iostream>
#include <string>
#include <cstdlib>
#include "MConsolUtil.hpp"
#include "MGameLoop.hpp"

class Enemy
{
public:
	int x = 50;
	int y = 7;

	Enemy()
	{
		y = 7;
	}
	~Enemy()
	{

	}
	void EnemyMove()
	{
		x--;
	}

	/*int x = 50, y;

	Enemy()
	{
		y = 7;
	}
	~Enemy()
	{

	}
	void EnemyMove()
	{
		x--;
		if (x == 0)
		{
			x = 50;
		}
	}*/
};
#pragma once
