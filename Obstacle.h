#pragma once
#include "Cell.h"
class Obstacle
{
public:
	Obstacle();
	Obstacle(int x, int y, std::vector<std::vector<char>> shape);
	void move(direction direct); //0: up 1: down 2: left 3: right
	void display();
	void remove();
	virtual void tell();
	virtual ~Obstacle();
private:
	Cell shape;
};

