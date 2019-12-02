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
	void process(CPeople* a);
	void processLight();
	void processVehicle(CPeople* player);


	void save(std::ofstream &fileGame);
	void load(std::ifstream &fileGame);

private:
	Obstacle* light;
	bool isLight, color = 0;
	int lightSpeed;
};

#endif // !ROADVEHICLE_H
