#include "RoadVehicle.h"
#include "Screen.h"
#include <thread>

RoadVehicle::RoadVehicle() {
	init();
}

RoadVehicle::RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct) 
 : Road(offset, maxObject, type, objRow, objectSpeed, direct) {
	init();
}

void RoadVehicle::init() {
	isLight = random(0, 1);
	lightSpeed = random(3, 10) * 150;

	if (direct == Left) light = factory.getInstance(Light, Width + 3, objRow);
	else if (direct == Right) light = factory.getInstance(Light, Width + 3, objRow);
	else EXIT_ERROR("FUCK", -1);
}

void RoadVehicle::processLight() {
	if (!isLight) return;
	light->display(1);
	light->changeColor(color);
	
	while (!EXIT) {
		Sleep(lightSpeed);
		color = 1 - color;
		light->changeColor(color);
	}
}

void RoadVehicle::processVehicle() {
	while (!endSignal) {
		while (!pauseSignal) {
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				EXIT = 1; return;
			}

			if (!color) update();
			Sleep(objectSpeed);
		}
	}
}

void RoadVehicle::process() {
	std::thread th1(&RoadVehicle::processVehicle, this);
	std::thread th2(&RoadVehicle::processLight, this);
	th2.join();
	th1.join();
}
