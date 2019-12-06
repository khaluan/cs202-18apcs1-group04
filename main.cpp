#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"
#include "Level.h"

int main() {
	initScreen();

	CGame game;
	game.Run();
	//Screen scr;
	//std::string dir = scr.saveMenu();

	/*Screen X;
	std::vector<std::string> tmp = X.inputPlayer_Menu();
	std::cout << tmp[0] << "     " << tmp[1] << std::endl;*/
	/*Screen X;
	std::string tmp;
	tmp = X.saveMenu();
	std::cout << std::endl << "*************************" << std::endl << tmp << std::endl;*/

	return 0;
}