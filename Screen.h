#ifndef SCREEN_H
#define SCREEN_H

#include "Support.h"

const int Height = 50;
const int Width = 180;

enum mainChoice {
	NEWGAME,
	LOADGAME,
	SETTING
};

enum pauseChoice {
	YES,
	NO
};

enum menuType {
	MAIN,
	PAUSE
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
	std::string saveChoice();
	std::string loadMenu();
	std::string loadChoice(int index);
	std::vector<std::string> loadList();

	template<class T>
	T menu(const menuType& type, T init);
	
	
private:
	const int height = 30, width = 100, sleepTime = 200, xPos = 20, yPos = 10; //Fix later
	std::string saveDir = "SavedGame/";
	std::string loadDir = "SavedGame/";
	std::string loadChoice_Dir = "Data/";
	std::vector<std::string> pauseChoice_list{ "YES", "NO" };
	std::vector<std::string> mainChoice_list{ "New game", "Load game", "Setting", "Exit" };
	
};

template<class T>
T Screen::menu(const menuType& type, T init) {
	system("cls");
	Sleep(sleepTime);
	std::vector<std::string> choiceList;
	if (type == MAIN) choiceList = mainChoice_list;
	else if (type == PAUSE) {
		choiceList = pauseChoice_list;
		gotoXY(xPos, yPos);
		std::cout << "Do you want to continue ?" << std::endl;
	}
	int state = 1, s = 1, sNum = choiceList.size();

	while (1)
	{
		if (s <= sNum) {
			setColor(10);
			gotoXY(xPos, yPos + s);
			std::cout << choiceList[s - 1];
			setColor(7);
			for (int i = 0; i < sNum; ++i) {
				if (i == (s - 1)) continue;

				gotoXY(xPos, yPos + (i + 1));
				std::cout << choiceList[i];
			}
		}
		else {
			init = (T)(state - 1);
			return init;
		}

		s = stateMove(state, sNum);
	}
	std::cin.ignore(1000, '\n');
}

#endif // !SCREEN_H
