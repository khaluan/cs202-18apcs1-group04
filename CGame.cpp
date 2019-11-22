#include "CGame.h"
#include <thread>

CGame::CGame() {
	arrRoad.clear();
	level = 1;
	sizeArr = 0;

	initLevel();
}

void CGame::initLevel() {
	// int offset,int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct
	int typeRoad;
	sizeArr = random(3, 5);
	for (int i = 0; i < sizeArr; ++i) {
		typeRoad = random(0, 1);
		if (typeRoad == 0) {
			switch (level){
			case 1:
				arrRoad.push_back(new Road(3, random(4, 7), ObstacleType(random(2, 3)), 3 + 3 * i, random(1, 3) * 150, direction(random(2, 3))));
			default:
				break;
			}
		}
		else if (typeRoad == 1) {
			switch (level) {
			case 1:
				arrRoad.push_back(new RoadVehicle(3, random(4, 7), ObstacleType(random(0, 1)), 3 + 3 * i, random(1, 3) * 150, direction(random(2, 3))));
			default:
				break;
			}
		}
		else EXIT_ERROR("CGAME::CGAME()", -1);
	}
}

void CGame::process() {
	std::thread *th = new std::thread[sizeArr];
	for (int i = 0; i < sizeArr; ++i) {
		th[i] = std::thread(&Road::process, arrRoad[i]);
	}

	for (int i = 0; i < sizeArr; ++i)
		th[i].join();

	delete[]th;
}