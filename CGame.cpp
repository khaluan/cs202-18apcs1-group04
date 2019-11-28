#include "CGame.h"
#include <thread>

CGame::CGame() {
	arrRoad.clear();
	level = 1;
	player = new CPeople(1, 27);
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

	sizeArr = random(3, 5);
	
	for (int i = 1; i <= sizeArr; ++i) {
		typeRoad = random(0, 1);
		if (typeRoad == 0) {
			switch (level){
			case 1:
				arrRoad.push_back(new Road(2, random(4, 7), ObstacleType(random(2, 3)), 3 + 4 * i, random(1, 3) * 60, direction(random(2, 3))));
			default:
				break;
			}
		}
		else if (typeRoad == 1) {
			switch (level) {
			case 1:
				arrRoad.push_back(new RoadVehicle(2, random(4, 7), ObstacleType(random(0, 1)), 3 + 4 * i, random(1, 3) * 60, direction(random(2, 3))));
			default:
				break;
			}
		}
		else EXIT_ERROR("CGAME::CGAME()", -1);
	}

	for (int i = 0; i < sizeArr; ++i)
		arrRoad[i]->displayOutline();
}


void CGame::process() {
	std::thread *th = new std::thread[sizeArr];
	
	for (int i = 0; i < sizeArr; ++i)
		th[i] = std::thread(&Road::process, arrRoad[i], player);

	player->display();

	while (player->getState()) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			player->move(Up);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			player->move(Down);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			player->move(Left);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			player->move(Right);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if (GetAsyncKeyState('P') & 0x8000) {//TODO: Bug press any key else unpause the game
			Road::CHANGE_PAUSE();
			Sleep(100);
			
			while (true) {
				if (GetAsyncKeyState('P') & 0x8000) break;
			}
			Road::CHANGE_PAUSE();

			Sleep(100);
			//menuPause();
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			break;
		}
	}

	Road::CHANGE_END_TASK();

	for (int i = 0; i < sizeArr; ++i)
		th[i].join();

	delete[]th;
}

