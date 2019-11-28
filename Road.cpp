#include "Road.h"
ObstacleFactory Road::factory = ObstacleFactory();
bool Road::END_TASK = false;
bool Road::PAUSE = false;

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

void Road::update(CPeople* player)
{
	for (unsigned i = 0; i < arr.size(); ++i) {
		player->CheckCrash(*arr[i]);
		arr[i]->move(direct);
	}
}

void Road::CHANGE_END_TASK() {
	END_TASK = 1 - END_TASK;
}

void Road::CHANGE_PAUSE() {
	PAUSE = 1 - PAUSE;
}

void Road::process(CPeople* player)
{
	while (!END_TASK) {
		while (PAUSE) { }
		update(player);
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


