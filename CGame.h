#ifndef CGAME_H
#define CGAME_H
#include <fstream>
#include <ctime>
#include <chrono>
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include "Screen.h"

class CGame {
public:
	CGame();
	CGame(int level);
	~CGame();
	void saveGame(const std::string& gameName);
	void loadGame(const std::string& gameName);
	void initLevel(int level);
	void process();
private:
	const int SLEEP_TIME_BETWEEN_SCREEN = 100;
	std::vector<Road*> arrRoad;
	CPeople* player;
	int level, sizeArr;
	Screen scr;
};

//class Data {
//private:
//	std::string name;
//	Time t;
//	int level;
//};
//
//class CGame {
//public:
//	CGame();
//	~CGame();
//
//	void menuMain();
//private:
//	void initLevel(int);
//	void process(Data);
//
//	void menuPause(); 
//	void menuNewGame(); //read info player and level
//	void menuContinue(); //loading game
//	void menuScoreBoard();
//
//private:
//	void drawPause();
//	void drawNewGame();
//	void drawContinue();
//	void drawMenuScoreBoard();
//
//private:
//	const int SLEEP_TIME_BETWEEN_SCREEN = 200;
//	std::vector<Data> arrData;
//
//};
//
//void CGame::menuMain() {
//	Sleep(SLEEP_TIME_BETWEEN_SCREEN);
//	system("cls");
//	drawMain();
//
//	// doSth;
//}

#endif // !CGAME_H
