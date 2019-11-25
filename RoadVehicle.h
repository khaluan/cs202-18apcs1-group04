#pragma once
#include "Light.h"
#include "Road.h"
#include "Obstacle.h"

class RoadVehicle :public Road {
public:
	RoadVehicle();
	RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	void init();
	void process(CPeople* player = nullptr);
	void processLight();
	void processVehicle();
private:
	Obstacle* light;
	bool isLight, color = 0, EXIT = 0;
	int lightSpeed;
};
