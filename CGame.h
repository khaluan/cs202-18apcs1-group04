#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"

class CGame {
public:
private:
	std::vector<Road*> arrRoad;
	CPeople player;
};

#endif // !CGAME_H
