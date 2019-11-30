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
	SetConsoleTextAttribute(color, k);
}

void EXIT_ERROR(std::string defineErr, int code) {
	system("cls");
	std::cout << defineErr << std::endl;
	exit(code);
}

int random(int l, int r) {
	return rand() % (r - l + 1) + l;
}

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

std::vector<std::string> read_directory(const std::string& directory)
{
	std::vector<std::string> v;
	std::string pattern(directory), x;
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {

		do {
			x = data.cFileName;
			if (x.length() <= 4) continue;
			v.push_back(data.cFileName);

		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	return v;
}