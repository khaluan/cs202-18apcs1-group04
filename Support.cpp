#include "Support.h"

void fixConsoleScreen()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int k) {
	SetConsoleTextAttribute(color, 10);
}

void EXIT_ERROR(std::string defineErr, int code) {
	system("cls");
	std::cout << defineErr << std::endl;
	exit(code);
}