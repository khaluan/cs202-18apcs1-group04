#include "RoadVehicle.h"
#include "Screen.h"

RoadVehicle::RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct)
	: Road(offset, maxObject, type, objRow, objectSpeed, direct)
{
	if (direct == 2) light = TrafficLight(Width, objRow);
	else if (direct == 3) light = TrafficLight(1, objRow);
	else EXIT_ERROR("Wrong init RoadVehicle: direct = " + char(direct + '0'), 1);
}

void RoadVehicle::process() {
	while (1) {
		Road::process();
		//TODO: light.process()
	}
}