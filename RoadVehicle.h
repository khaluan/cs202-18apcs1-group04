#ifndef ROADVEHICLE_H
#define ROADVEHICLE_H

#include "Light.h"
#include "Road.h"
#include "Obstacle.h"

class RoadVehicle :public Road {
public:
	RoadVehicle();
	RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	void init();
	void process(CPeople* player);
	void processLight();
	void processVehicle(CPeople* player);
private:
	Obstacle* light;
	bool isLight, color = 0, EXIT = 0;
	int lightSpeed;
};

#endif // !ROADVEHICLE_H
