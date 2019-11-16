#include "CPeople.h"

CPeople::CPeople(int _x, int _y)
{
	x = _x;
	y = _y;
}

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

bool CPeople::isFinish(const int & height)
{
	return y == height - 1;
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
