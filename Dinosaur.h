#pragma once
#include "Obstacle.h"
class CDinosaur :
	public Obstacle
{
public:
	CDinosaur(int x, int y, std::vector<std::vector<char>> shape);
	~CDinosaur();
};

