#include "CPeople.h"
#include "Road.h"

CPeople::CPeople()
{
	shape = Cell(4, 4, readShape("Human.txt"));
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

std::vector<std::vector<std::vector<char>>> CPeople::readShape(const std::string& dir) {
	std::string directory = "Data/" + dir;
	std::ifstream fin;
	fin.open(directory);
	if (fin.is_open()) {
		int num, h, w; fin >> num >> h >> w;
		std::vector<std::vector<std::vector<char>>> tmp(num, std::vector<std::vector<char>>(h, std::vector<char>(w)));
		for (int k = 0; k < num; ++k)
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w; ++j) {
					int val; fin >> val;
					tmp[k][i][j] = char(val);
				}
		fin.close();
		return tmp;
	}
	else
		EXIT_ERROR("File at " + directory + " not found", -1);
}

void CPeople::move(const direction& d) {
	if (shape.move(d)) state = false;
}

bool CPeople::isFinish()
{
	if (shape.getY() == 0) return true;
	return false;
}

void CPeople::turnState()
{
	state = 1 - state;
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

void CPeople::save(std::ofstream& fileGame)
{
	shape.save(fileGame);
}

void CPeople::load(std::ifstream& fileGame)
{
	shape.load(fileGame);
}

CPeople::~CPeople()
{
}
