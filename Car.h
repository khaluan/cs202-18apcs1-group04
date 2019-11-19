#pragma once
#include "Obstacle.h"
class CCar :
	public Obstacle
{
public:
	CCar(int x, int y, std::vector<std::vector<char>> shape);
	~CCar();
};

