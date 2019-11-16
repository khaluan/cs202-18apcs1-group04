#include "Road.h"
Road::Road()
{
}

Road::Road(int a, int b)
{
	upper = a;
	lower = b;
}

void Road::display(const int & height, const int & width)
{
	for (int i = 0; i < width; i++) {
		gotoXY(i, upper);
		std::cout << (char)205;
		gotoXY(i, lower);
		std::cout << (char)205;
	}

}


Road::~Road()
{
}
