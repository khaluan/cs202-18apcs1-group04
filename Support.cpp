#include "Support.h"

void initScreen(const int& ySize) {
	//HWND console = GetConsoleWindow();
	//RECT r;
	//GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	//MoveWindow(GetConsoleWindow(), 0, 0, 1900, 800, TRUE);
	m.lock();
	CONSOLE_FONT_INFOEX cfi;
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = ySize;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//fixConsoleScreen(); 
	//srand(time(NULL));
	//ShowConsoleCursor(false);
	m.unlock();
}

void fixScreen() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 0, 0, 2000, 1000, TRUE);
	fixConsoleScreen();
	srand(time(NULL));
	ShowConsoleCursor(false);
}

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

void instruction() {
	m.lock();
	int instructX = 210, instructY = 0;
	setColor(5);
	for (int i = 0; i < instructX + 36; ++i) {
		gotoXY(i, instructY);
		std::cout << (char)205;
	}
	for (int i = 0; i < instructX + 36; ++i) {
		gotoXY(i, instructY + 45);
		std::cout << (char)205;
	}
	for (int i = 0; i < instructX + 36; ++i) {
		gotoXY(i, instructY + 50);
		std::cout << (char)205;
	}
	for (int i = 0; i < 51; ++i) {
		gotoXY(instructX, instructY + i);
		std::cout << (char)186;
		gotoXY(instructX + 36, instructY + i);
		std::cout << (char)186;
	}
	setColor(14);
	gotoXY(instructX + 5, instructY + 7);
	std::cout << "Use        W        to move";
	gotoXY(instructX + 5, instructY + 8);
	std::cout << "       A   S   D";
	gotoXY(instructX + 5, instructY + 10);
	std::cout << "    W or UP to move up";
	gotoXY(instructX + 5, instructY + 12);
	std::cout << "    A or LEFT to move left";
	gotoXY(instructX + 5, instructY + 14);
	std::cout << "    S or DOWN to move down";
	gotoXY(instructX + 5, instructY + 16);
	std::cout << "    D or RIGHT to move right";
	gotoXY(instructX + 5, instructY + 20);
	std::cout << "    P to PAUSE GAME";
	gotoXY(instructX + 5, instructY + 22);
	std::cout << "    T to LOAD GAME";
	gotoXY(instructX + 5, instructY + 24);
	std::cout << "    L to SAVE GAME";

	gotoXY(instructX + 5, instructY + 30);
	std::cout << "Cross the all the roads to win";
	gotoXY(instructX + 5, instructY + 32);
	std::cout << "Avoid to get hit or DIE";
	setColor(7);
	m.unlock();
}