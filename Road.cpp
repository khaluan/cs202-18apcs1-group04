#include "Road.h"
ObstacleFactory Road::factory = ObstacleFactory();
Road::Road()
{
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
	for (int i = 0; i < maxObject; ++i) {
		Obstacle *ptr = nullptr;
		if (direct == 2) ptr = factory.getInstance(type, Width + i * 3, objRow);
		if (direct == 3) ptr = factory.getInstance(type, 1 - i * 3, objRow);
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
	update();
	Sleep(objectSpeed);
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
