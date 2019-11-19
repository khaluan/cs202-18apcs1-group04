#pragma once
#include "Light.h"
#include "Road.h"

class RoadVehicle :public Road {
public:
	RoadVehicle() = default;
	RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	void process();
private:
	TrafficLight light;
};
