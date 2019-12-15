#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"
#include "Level.h"

int main() {
	fixScreen();

	CGame game;
	game.Run();
	

	/*Screen X;*/
	//instruction();

	//std::string dir = scr.saveMenu();

	/*std::vector<std::string> tmp = X.inputPlayer_Menu();
	std::cout << tmp[0] << "     " << tmp[1] << std::endl;*/
	
	/*std::string tmp;
	tmp = X.saveMenu();
	std::cout << std::endl << "*************************" << std::endl << tmp << std::endl;*/

	return 0;
}