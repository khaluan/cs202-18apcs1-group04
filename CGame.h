#ifndef CGAME_H
#define CGAME_H
#include <fstream>
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
	const int SLEEP_TIME_BETWEEN_SCREEN = 100;
	std::vector<Road*> arrRoad;
	CPeople* player;
	int level, sizeArr;
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
