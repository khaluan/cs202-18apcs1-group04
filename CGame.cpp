#include "CGame.h"
#include <thread>

CGame::CGame() {
	arrRoad.clear();
	level = 1;
	player = new CPeople(1, 1);
	sizeArr = 0;

	initLevel();
}

CGame::~CGame() {
	delete player;
	for (int i = 0; i < sizeArr; ++i)
		delete arrRoad[i];
}

void CGame::initLevel() {
	// int offset,int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct
	int typeRoad;
	sizeArr = random(5, 8);
	for (int i = 0; i < sizeArr; ++i) {
		typeRoad = random(0, 1);
		if (typeRoad == 0) {
			switch (level){
			case 1:
				arrRoad.push_back(new Road(3, random(4, 7), ObstacleType(random(2, 3)), 3 + 3 * i, random(1, 3) * 100, direction(random(2, 3))));
			default:
				break;
			}
		}
		else if (typeRoad == 1) {
			switch (level) {
			case 1:
				arrRoad.push_back(new RoadVehicle(3, random(4, 7), ObstacleType(random(0, 1)), 3 + 3 * i, random(1, 3) * 100, direction(random(2, 3))));
			default:
				break;
			}
		}
		else EXIT_ERROR("CGAME::CGAME()", -1);
	}
}

void CGame::process() {
	std::thread *th = new std::thread[sizeArr + 1];
	
	th[sizeArr - 1] = std::thread(&CPeople::move, player, 4, 4);
	
	for (int i = 0; i < sizeArr - 1; ++i) {
		th[i] = std::thread(&Road::process, arrRoad[i]);
	}
	 
	th[sizeArr - 1].join();

	Road::CHANGE_END_TASK();

	for (int i = sizeArr - 2; i >= 0; --i)
		th[i].join();

	delete[]th;
}