#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"
#include "Level.h"
#include <Windows.h>
#include <sstream>
#include <iomanip>
#include <time.h>

int main() {
	fixScreen();

	CGame game;
	game.Run();

	//initScreen(24);
	//Screen X;
	//X.saveScreen();
	//X.settingMenu();
	//instruction();
	//std::string dir = scr.saveMenu();

	//std::vector<std::string> tmp = X.inputPlayer_Menu();
	//std::cout <<std::endl<< tmp[0] << "     " << tmp[1] << std::endl;
	
	/*std::string tmp;
	tmp = X.saveMenu();
	std::cout << std::endl << "*************************" << std::endl << tmp << std::endl;*/

	//system("cls");
	return 0;
}