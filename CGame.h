#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"

class CGame {
public:
	CGame();
	~CGame();
	void initLevel();
	void process();
private:
	std::vector<Road*> arrRoad;
	CPeople* player;
	int level, sizeArr;
};

#endif // !CGAME_H
