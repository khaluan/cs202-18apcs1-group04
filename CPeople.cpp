#include "CPeople.h"

CPeople::CPeople()
{
	x = 1;
	y = 30;
	this->shape = Cell(1, 30, readShape("Human.txt"));
}

CPeople::CPeople(int x, int y)
{
	this->x = x;
	this->y = y;
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

void CPeople::move(char ch) {
	while (!isFinish(Height))
	{
		switch (ch)
		{
		case 's':

			shape.move(Down, stepX, stepY);
			Sleep(100);
			break;

		case 'w':

			shape.move(Up, stepX, stepY);
			Sleep(100);
			break;

		case 'd':

			shape.move(Right, stepX, stepY);
			Sleep(100);
			break;

		case 'a':
			shape.move(Left, stepX, stepY);
			Sleep(100);
			break;

		/*case 'p':

			while (1) {
				char c = _getch();
				if (c == 'p') break;
			}
			m.unlock();

			break;*/
		default:
			break;
		}

		/*shape.remove();
		shape.init(x,y);
		shape.draw();*/
		return;
	}
}
bool CPeople::isFinish(const int & height)
{
	if (y == 0) return true;
	return false;
}

void CPeople::display()
{
	gotoXY(x, y);
	std::cout << (char)177;
	gotoXY(x, y + 1);
	std::cout << (char)197;

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

CPeople::~CPeople()
{
}
