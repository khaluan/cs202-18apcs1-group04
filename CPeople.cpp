#include "CPeople.h"
#include "Road.h"

CPeople::CPeople()
{
	shape = Cell(1, 4, readShape("Human.txt"));
}

CPeople::CPeople(int x, int y)
{
	this->shape = Cell(x, y, readShape("Human.txt"));
}

/*
void CPeople::move(const char & c, const int & stepx, const int & stepy, const int & height, const int & width)
{
	//remove the last position
	gotoXY(x, y);
	std::cout << " ";
	gotoXY(x, y + 1);
	std::cout << " ";

	switch (c)
	{
	case 'w':
		y = max(0, y - stepy);
		break;
	case 's':
		y = min(height - 1, y + stepy);
		break;
	case 'a':
		x = max(0, x - stepx);
		break;
	case 'd':
		x = min(width - 1, x + stepx);
		break;
	default:
		break;
	}
}
*/

std::vector<std::vector<char>> CPeople::readShape(const std::string& dir) {
	std::string directory = "Data/" + dir;
	std::ifstream fin;
	fin.open(directory);
	if (fin.is_open()) {
		int h, w; fin >> h >> w;
		std::vector<std::vector<char>> tmp(h, std::vector<char>(w));
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				int val; fin >> val;
				tmp[j][i] = char(val);
			}
		fin.close();
		return tmp;
	}
	else
		EXIT_ERROR("File at " + directory + " not found", -1);
}

void CPeople::move(const direction& d) {
	shape.move(d);
}
bool CPeople::isFinish(const int& height)
{
	if (shape.getY() == 0) return true;
	return false;
}

void CPeople::CheckCrash(Obstacle& a) {
	if (a.crash(shape)) state = false;
}

bool CPeople::isDead()
{
	//TODO: 
	//return isImpact(animal) | isImpact(vehicle);
	return false;
}

void CPeople::update()
{
	//TODO: 
}

bool CPeople::getState()
{
	return state;
}

int CPeople::getX()
{
	return shape.getX();
}

int CPeople::getY()
{
	return shape.getY();
}

void CPeople::display() {
	shape.draw();
}

CPeople::~CPeople()
{
}
