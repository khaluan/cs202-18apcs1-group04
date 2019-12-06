#include "Road.h"
ObstacleFactory Road::factory = ObstacleFactory();
bool Road::PAUSE = false;
bool Road::EXIT = false;

Road::Road() {
	addObject(this->type);
}

Road::~Road() {
	for (auto p : arr)
		delete p;
	arr.clear();
}

Road::Road(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct)
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
	int curX = (direct == 2) ? 1 : Width;
	for (int i = 0; i < maxObject; ++i) {
		Obstacle* ptr = nullptr;

		if (direct == 2) curX += random(2, 4) * 9;
		if (direct == 3) curX -= random(2, 4) * 9;

		if (direct == 2) ptr = factory.getInstance(type, curX, objRow);
		if (direct == 3) ptr = factory.getInstance(type, curX, objRow);
		if (ptr)
			arr.push_back(ptr);
	}
}

void Road::update(CPeople* a) {
	for (unsigned i = 0; i < arr.size(); ++i) {
		if (arr[i]->move(direct)) a->turnState();
	}
}

void Road::CHANGE_PAUSE() {
	PAUSE = 1 - PAUSE;
}

void Road::CHANGE_EXIT() {
	EXIT = 1 - EXIT;
}

void Road::process(CPeople* a)
{
	while (!EXIT) {
		while (PAUSE) {}
		update(a);
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

void Road::save(std::ofstream & gameFile)
{
	gameFile << 0 << std::endl;
	saveHelper(gameFile);
}

void Road::saveHelper(std::ofstream & gameFile)
{
	gameFile << offset << " " << arr.size() << " " << objRow << " "
		<< objectSpeed << " " << direct << " " << type << std::endl;
	for (unsigned i = 0; i < arr.size(); ++i)
		arr[i]->save(gameFile);
}

void Road::load(std::ifstream & gameFile)
{
	int directVal, typeVal;
	gameFile >> offset >> maxObject >> objRow >> objectSpeed >> directVal >> typeVal;
	direct = (direction)directVal;
	type = (ObstacleType)typeVal;
	arr.resize(maxObject);
	for (unsigned i = 0; i < arr.size(); ++i) {
		int x, y;
		gameFile >> x >> y;
		arr[i] = Road::factory.getInstance(type, x, y);
	}
}

bool Road::isPause()
{
	return PAUSE;
}

bool Road::isExit()
{
	return EXIT;
}

direction Road::getDirection()
{
	return direct;
}

int Road::getObjRow()
{
	return objRow;
}

