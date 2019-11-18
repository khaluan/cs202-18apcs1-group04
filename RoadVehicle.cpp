#include "RoadVehicle.h"
#include "Screen.h"
#include "Support.h"

RoadVehicle::RoadVehicle() {
	init();
}

RoadVehicle::RoadVehicle(int n, int y, int sV, int sL, int direct, bool ok) {
	_n = n; _y = y; speedVehicle = sV; speedLight = sL; _direct = direct; isLight = ok;
}

void RoadVehicle::init() {
	if (isLight) {
		if (_direct == 2) light = TrafficLight(Width, _y);
		else if (_direct == 3) light = TrafficLight(1, _y);
		else EXIT_ERROR("Wrong init RoadVehicle: direct = " + char(_direct + '0'), 1);
	}
	for (int i = 0; i < _n; ++i) {
		if (_direct == 2) arr.push_back(CVehicle(Width + i * 3, _y));
		if (_direct == 3) arr.push_back(CVehicle(1 - i * 3, _y));
	}

}

void RoadVehicle::Process() {
	while (1) {
		for (int i = 0; i < _n; ++i) arr[i].move(_direct);
		Sleep(speedVehicle);
	}
}