#include "CGame.h"
#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"

int main() {
	initScreen();
	
	CGame a;
	a.Run();
	Screen::destructor();


	return 0;
}