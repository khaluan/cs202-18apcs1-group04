#include "Screen.h"
#include <Windows.h>

bool* Screen::screen = Screen::constructor();

Screen::Screen() {
	for (int i = 0; i < Height; ++i)
		for (int j = 0; j < Width; ++j)
			screen[i * Width + j] = 255;
}


Screen::~Screen()
{
}


int Screen::stateMove(int& state, int n)
{
	//ShowConsoleCursor(false);

	while (1)
	{
		char ch = _getch();
		switch (ch)
		{
		case 72:

			if (state > 1)
			{
				state -= 1;
			}
			else
			{
				state = n;
			}

			Sleep(300);
			//system("cls");
			return state;

		case 75:

			if (state > 1)
			{
				state -= 1;
			}
			else
			{
				state = n;
			}

			Sleep(300);
			//system("cls");
			return state;

		case 77:

			if (state < n)
			{
				state += 1;
			}
			else
			{
				state = 1;
			}
			Sleep(300);
			//	system("cls");
			return state;

		case 80:

			if (state < n)
			{
				state += 1;
			}
			else
			{
				state = 1;
			}
			Sleep(300);
			//	system("cls");
			return state;

		case 13:
			return n + 1;

		}
	}
}

int Screen::pauseMenu()
{
	int state = 1, s = 1;
	gotoXY(1, 32);
	std::cout << "Do you wish to continue: " << std::endl;
	while (1)
	{
		switch (s)
		{

		case 1:
			//system("cls");
			setColor(10);
			gotoXY(1, 33);
			std::cout << "YES";
			setColor(7);

			gotoXY(1, 34);
			std::cout << "No";

			s = stateMove(state, 2);
			break;
		case 2:
			//system("cls");
			gotoXY(1, 33);
			std::cout << "YES";

			setColor(10);
			gotoXY(1, 34);
			std::cout << "No";
			setColor(7);


			s = stateMove(state, 2);
			break;
		case 3:
			return state;
		}
	}
	std::cin.ignore(1000, '\n');
}

bool* Screen::constructor() {
	bool* res = new bool[5000];
	for (int i = 0; i < 5000; ++i) res[i] = 0;
	return res;
}

void Screen::setScreen(int i, int j, int c) {
	screen[i * Width + j] = c;
}

bool Screen::isPixelNull(int i, int j) {
	return screen[i * Width + j] == 0;
}