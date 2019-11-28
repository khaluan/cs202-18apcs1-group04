#ifndef TRUCK_H
#define TRUCK_H

#include "Obstacle.h"
class CTruck :
	public Obstacle
{
public:
	CTruck(int x, int y, std::vector<std::vector<char>> shape);
	~CTruck();
};

#endif // !TRUCK_H
