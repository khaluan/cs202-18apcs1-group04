#ifndef DINOSAUR_H
#define DINOSAUR_H

#include "Obstacle.h"
class CDinosaur :
	public Obstacle
{
public:
	CDinosaur(int x, int y, std::vector<std::vector<char>> shape);
	~CDinosaur();
};

#endif // !DINOSAUR_H
