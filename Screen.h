#ifndef SCREEN_H
#define SCREEN_H

#include "Support.h"

const int Height = 30;
const int Width = 100;

enum mainChoice {
	NEWGAME,
	LOADGAME,
	SETTING
};

enum pauseChoice {
	YES,
	NO
};


class Screen
{
public:
	Screen();
	~Screen();
	int stateMove(int& state, int n);
	std::vector<std::string> inputPlayer_Menu();
	pauseChoice pauseMenu();
	mainChoice mainMenu();
	std::string saveMenu();
	std::string loadMenu();
	std::string loadChoice(int index);
	std::vector<std::string> loadList();

	static bool* constructor();
	static void setScreen(int i, int j, int c);
	static bool isPixelNull(int i, int j);
private:
	const int height = 30, width = 100, sleepTime = 200, xPos = 20, yPos = 10; //Fix later
	std::string saveDir = "Data/";
	std::string loadDir = "Data/";
	std::string loadChoice_Dir = "Data/";
	static bool* screen;
};

#endif // !SCREEN_H
