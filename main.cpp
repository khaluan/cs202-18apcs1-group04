#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"

int main() {
	/*srand(time(NULL));
	ShowConsoleCursor(false);
	
	CGame a;
	a.process();*/

	Screen X;
	std::string tmp;
	tmp = X.saveMenu();
	std::cout << std::endl << "*************************" << std::endl << tmp << std::endl;
	return 0;
}