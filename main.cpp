#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"

int main() {
	srand(time(NULL));
	ShowConsoleCursor(false);
	
	CGame a;
	a.process();

	/*Screen X;
	std::vector<std::string> tmp = X.inputPlayer_Menu();
	std::cout << tmp[0] << "     " << tmp[1] << std::endl;*/
	return 0;
}