#pragma once
#include "Obstacle.h"
class CTruck :
	public Obstacle
{
public:
	CTruck(int x, int y, std::vector<std::vector<char>> shape);
	~CTruck();
};

