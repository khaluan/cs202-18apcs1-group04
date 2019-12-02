#include "Truck.h"

CTruck::CTruck(int x, int y, std::vector<std::vector<std::vector<char>>> shape)
	: Obstacle(x, y, shape)
{
}


CTruck::~CTruck()
{
}
