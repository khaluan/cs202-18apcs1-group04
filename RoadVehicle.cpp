#include "RoadVehicle.h"
#include "Screen.h"
#include <thread>

RoadVehicle::RoadVehicle() {
	
}

RoadVehicle::RoadVehicle(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct) 
 : Road(offset, maxObject, type, objRow, objectSpeed, direct) {
	init();
}

void RoadVehicle::init() {
	isLight = 1;
	lightSpeed = random(4, 6) * 500;

	if (direct == Left) light = factory.getInstance(Light, Width + 5, objRow);
	else if (direct == Right) light = factory.getInstance(Light, Width + 5, objRow);
	else EXIT_ERROR("FUCK", -1);
}

void RoadVehicle::processLight() {
	if (!isLight) return;
	light->display(isLight);
	light->changeColor(color);
	
	bool ok = 0;

	while (!EXIT) {
		Sleep(lightSpeed);

		if (PAUSE) ok = 1;

		while (PAUSE) { }

		if (ok) {
			ok = 0;
			light->display(isLight);
		}

		color = 1 - color;
		light->changeColor(color);
	}
}

void RoadVehicle::processVehicle(CPeople* a) {

	while (!EXIT) {
		while (PAUSE) {}
		if (!color) update(a);
		Sleep(objectSpeed);
	}
}

void RoadVehicle::save(std::ofstream & fileGame)
{
	//fileGame << 1 << std::endl;
	int tmp = 1;
	fileGame.write((char*)&tmp, sizeof(tmp));
	Road::saveHelper(fileGame);
	//fileGame << color << " " << lightSpeed << std::endl;
	fileGame.write((char*)&color, sizeof(color));
	fileGame.write((char*)&lightSpeed, sizeof(lightSpeed));
}

void RoadVehicle::load(std::ifstream & fileGame)
{
	Road::load(fileGame);
	//fileGame >> color >> lightSpeed;
	fileGame.read((char*)&color, sizeof(color));
	fileGame.read((char*)&lightSpeed, sizeof(lightSpeed));
	if (direct == Left) light = factory.getInstance(Light, Width + 3, objRow);
	else if (direct == Right) light = factory.getInstance(Light, Width + 3, objRow);
}

void RoadVehicle::process(CPeople* a) {
	std::thread th1(&RoadVehicle::processVehicle, this, a);
	std::thread th2(&RoadVehicle::processLight, this);
	th2.join();
	th1.join();
}
