#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Cell.h"

class Obstacle
{
public:
	Obstacle();
	Obstacle(int x, int y, std::vector<std::vector<std::vector<char>>> shape);
	bool move(direction direct); //0: up 1: down 2: left 3: right
	void display(bool isLight = false);
	void remove();
	void changeColor(bool Color);
	
	void save(std::ofstream &fileGame);
	void load(std::ifstream &fileGame);

	virtual void tell();
	virtual ~Obstacle();
private:
	Cell shape;
};

#endif // !OBSTACLE_H
