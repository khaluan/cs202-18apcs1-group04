#include "CPeople.h"

CPeople::CPeople()
{
	x = 1;
	y = 1;
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

void CPeople::move(const int& stepx, const int& stepy) {
	while (!isFinish(Height))
	{
		shape.init(x,y);
		gotoXY(x, y);
		shape.draw();
		char ch = _getch();
		switch (ch)
		{
		case 's':

			if (y+stepy <= Height)
			{
				y += stepy;
			}
			else
			{
				y = Height;
			}

			Sleep(300);
			break;
			//system("cls");
			//return y;

		case 'w':

			if (y - stepy >= 0)
			{
				y -= stepy;
			}
			else
			{
				y = 0;
			}

			Sleep(300);
			break;
			//system("cls");
			//return state;

		case 'd':

			if (x + stepx <= Width)
			{
				x += stepx;
			}
			else
			{
				x = Width;
			}
			Sleep(300);
			break;
			//	system("cls");
			//return state;

		case 'a':

			if (x - stepx >= 0)
			{
				x -= stepx;
			}
			else
			{
				x = 0;
			}
			Sleep(300);
			break;
			//	system("cls");
			//return state;

		case 27:
			return;
		default:
			break;
		}
		shape.remove();
	}
}

bool CPeople::isFinish(const int & height)
{
	if (y == Height) return true;
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
