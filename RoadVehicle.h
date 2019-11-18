#ifndef ROADVEHICLE_H
#define ROADVEHICLE_H

#include "CVehicle.h"
#include "Light.h"
#include <vector>

class RoadVehicle {
public:
	RoadVehicle();
	RoadVehicle(int n, int y, int sV, int sL, int direct, bool ok);
	void init();
	void Process();
private:
	int _n = 3, _y = 5, speedVehicle = 1000, speedLight = 5000, _direct = 2;
	bool isLight = 0;
	std::vector <CVehicle> arr;
	TrafficLight light;
};

#endif // !ROADVEHICLE_H
