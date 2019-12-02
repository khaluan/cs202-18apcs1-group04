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
	lightSpeed = random(5, 10) * 400;

	if (direct == Left) light = factory.getInstance(Light, Width + 3, objRow);
	else if (direct == Right) light = factory.getInstance(Light, Width + 3, objRow);
	else EXIT_ERROR("FUCK", -1);
}

void RoadVehicle::processLight() {
	if (!isLight) return;
	light->display(isLight);
	light->changeColor(color);
	
	while (!EXIT) {
		while (PAUSE){ }
		Sleep(lightSpeed);
		color = 1 - color;
		light->changeColor(color);
	}
}

void RoadVehicle::processVehicle(CPeople* a) {

	while (!EXIT) {
		while (PAUSE){ }
		if (!color) update(a);
		Sleep(objectSpeed);
	}
}

void RoadVehicle::save(std::ofstream & fileGame)
{
	fileGame << 1 << std::endl;
	Road::saveHelper(fileGame);
	fileGame << color << " " << lightSpeed << std::endl;
}

void RoadVehicle::load(std::ifstream & fileGame)
{
	Road::load(fileGame);
	fileGame >> color >> lightSpeed;
}

void RoadVehicle::process(CPeople* a) {
	std::thread th1(&RoadVehicle::processVehicle, this, a);
	std::thread th2(&RoadVehicle::processLight, this);
	th2.join();
	th1.join();
}
