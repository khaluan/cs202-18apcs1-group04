#include "CGame.h"
#include <thread>

CGame::CGame() {
	arrRoad.clear();
	level = 1;
	player = new CPeople(4, 38);
	sizeArr = 0;
}

CGame::CGame(int level)
{
	arrRoad.clear();
	this->level = level;
	player = new CPeople(4, 38);
	sizeArr = 0;
	initLevel(level);
}



CGame::~CGame() {
	delete player;
	for (int i = 0; i < sizeArr; ++i)
		delete arrRoad[i];
}

void CGame::saveGame(const std::string & gameName)
{
	std::ofstream fileSave;
	fileSave.open(gameName);
	if (fileSave.is_open()) {
		auto time = std::chrono::system_clock::now();
		std::time_t save_time = std::chrono::system_clock::to_time_t(time);
		fileSave << save_time << std::endl;
		fileSave << level << std::endl;
		fileSave << sizeArr << std::endl;
		for (int i = 0; i < sizeArr; ++i)
			arrRoad[i]->save(fileSave);
		player->save(fileSave);
		fileSave.close();
	}
	else
		EXIT_ERROR("Cant open file to save", -1);
}

void CGame::loadGame(const std::string & gameName)
{
	std::ifstream gameFile;
	gameFile.open(gameName);
	if (gameFile.is_open()) {
		std::time_t time;
		gameFile >> time;
		gameFile >> level >> sizeArr;
		arrRoad.resize(sizeArr);
		for (int i = 0; i < sizeArr; ++i) {
			int type; gameFile >> type;
			if (type == 0)
				arrRoad[i] = new Road;
			else
				arrRoad[i] = new RoadVehicle;
			arrRoad[i]->load(gameFile);
		}
		player->load(gameFile);
		for (int i = 0; i < arrRoad.size(); ++i)
			arrRoad[i]->displayOutline();
		gameFile.close();
	}
	else
		EXIT_ERROR("Can open file " + gameName + " to load game", -1);
}

void CGame::initLevel(int level) {
	// int offset,int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct
	int typeRoad;

	sizeArr = random(4, 5);
	//sizeArr = 1;
	for (int i = 1; i <= sizeArr; ++i) {
		typeRoad = random(0, 1);
		if (typeRoad == 0) {
			switch (level){
			case 1:
				arrRoad.push_back(new Road(3, random(4, 6), ObstacleType(random(3, 3)), 2 + 6 * i, random(1, 3) * 100, direction(random(2, 3))));
			default:
				break;
			}
		}
		else if (typeRoad == 1) {
			switch (level) {
			case 1:
				arrRoad.push_back(new RoadVehicle(3, random(4, 6), ObstacleType(random(0, 1)), 2 + 6 * i, random(1, 3) * 100, direction(random(2, 3))))
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
	//loadGame("SavedGame/test.txt");
	std::thread *th = new std::thread[sizeArr];
	
	for (int i = 0; i < sizeArr; ++i)
		th[i] = std::thread(&Road::process, arrRoad[i], player);

	player->display();

	while (player->getState()) {
		if ((GetAsyncKeyState(VK_UP) | GetAsyncKeyState('W')) & 0x8000) {
			player->move(Up);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if ((GetAsyncKeyState(VK_DOWN) | GetAsyncKeyState('S')) & 0x8000) {
			player->move(Down);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if ((GetAsyncKeyState(VK_LEFT) | GetAsyncKeyState('A')) & 0x8000) {
			player->move(Left);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if ((GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState('D')) & 0x8000) {
			player->move(Right);
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
		}

		if (GetAsyncKeyState('P') & 0x8000) {//TODO: Bug press any key else unpause the game
			Road::CHANGE_PAUSE();
			Sleep(100);
		
			pauseChoice choice = scr.pauseMenu();
			Road::CHANGE_PAUSE();
			if (choice == YES) {
				for (int i = 0; i < sizeArr; ++i)
					arrRoad[i]->displayOutline();
			}
			else
				break;

			Sleep(100);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			break;
		}
	}

	Road::CHANGE_EXIT();

	for (int i = 0; i < sizeArr; ++i)
		th[i].join();

	delete[]th;
}

