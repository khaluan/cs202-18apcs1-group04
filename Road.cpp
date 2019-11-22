#include "Road.h"
ObstacleFactory Road::factory = ObstacleFactory();
Road::Road() {
	addObject(this->type);
}

Road::Road(int offset,int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct)
{
	this->offset = offset;
	this->maxObject = maxObject;
	this->objectSpeed = objectSpeed;
	this->objRow = objRow;
	this->direct = direct;
	this->type = type;
	addObject(this->type);
}

void Road::addObject(ObstacleType type)
{
	//TODO: Change the distance of the 2 consecutive objects
	int curX = (direct == 2) ? Width : 1;
	for (int i = 0; i < maxObject; ++i) {
		Obstacle *ptr = nullptr;

		if (direct == 2) curX += random(2, 7) * 3;
		if (direct == 3) curX -= random(2, 7) * 3;

		if (direct == 2) ptr = factory.getInstance(type, curX, objRow);
		if (direct == 3) ptr = factory.getInstance(type, curX, objRow);
		if (ptr)
			arr.push_back(ptr);
	}
}

void Road::update()
{
	for (unsigned i = 0; i < arr.size(); ++i)
		arr[i]->move(direct);
}

void Road::process()
{
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) return;
		update();
		Sleep(objectSpeed);
	}
}

void Road::displayOutline()
{
	for (int i = 0; i < Width; i++) {
		gotoXY(i, objRow - offset);
		std::cout << (char)205;
		gotoXY(i, objRow + offset);
		std::cout << (char)205;
	}
}

void Road::display()
{
	for (unsigned i = 0; i < arr.size(); ++i)
		arr[i]->display();
}

void Road::remove()
{
	for (unsigned i = 0; i < arr.size(); ++i)
		arr[i]->remove();
}

direction Road::getDirection()
{
	return direct;
}

int Road::getObjRow()
{
	return objRow;
}

Road::~Road()
{
	for (unsigned i = 0; i < arr.size(); ++i)
		delete arr[i];
	arr.clear();
}
