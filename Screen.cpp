#include "Screen.h"
#include <Windows.h>

bool* Screen::screen = Screen::constructor();

Screen::Screen() {
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
			return state;

		case 13:
			return n + 1;

		}
	}
}

std::vector<std::string> Screen::inputPlayer_Menu() {
	system("cls");
	std::vector<std::string> playerInfo;
	std::string name, time, date, now = __TIMESTAMP__;
	time = now.substr(11, 8);
	date = now.substr(0, 11);
	date += now.substr(20, 4);
	time += " " + date;

	gotoXY(xPos, yPos);
	std::cout << "Player name: ";
	std::getline(std::cin, name, '\n');
	playerInfo.push_back(name);
	playerInfo.push_back(time);
	return playerInfo;
}

pauseChoice Screen::pauseMenu()
{
	system("cls");
	Sleep(sleepTime);
	int state = 1, s = 1, sNum = 2;
	gotoXY(xPos, yPos);
	std::cout << "Do you want to continue ?" << std::endl;
	while (1)
	{
		switch (s)
		{

		case 1:
			setColor(10);
			gotoXY(xPos, yPos+1);
			std::cout << "YES";
			setColor(7);

			gotoXY(xPos, yPos+2);
			std::cout << "NO";

			s = stateMove(state, sNum);
			break;
		case 2:
			gotoXY(xPos, yPos+1);
			std::cout << "YES";

			setColor(10);
			gotoXY(xPos, yPos+2);
			std::cout << "NO";
			setColor(7);


			s = stateMove(state, sNum);
			break;
		case 3:
			return (pauseChoice)(state - 1);
		}
	}
	std::cin.ignore(1000, '\n');
}

mainChoice Screen::mainMenu()
{
	system("cls");
	Sleep(sleepTime);
	int state = 1, s = 1, sNum = 4;
	while (1)
	{
		switch (s)
		{

		case 1:
			setColor(10);
			gotoXY(xPos, yPos);
			std::cout << "New game";
			setColor(7);

			gotoXY(xPos, yPos + 1);
			std::cout << "Load game";
			gotoXY(xPos, yPos + 2);
			std::cout << "Setting";

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 2:
			gotoXY(xPos, yPos);
			std::cout << "New game";

			setColor(10);
			gotoXY(xPos, yPos + 1);
			std::cout << "Load game";
			setColor(7);
			
			gotoXY(xPos, yPos + 2);
			std::cout << "Setting";

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 3:
			gotoXY(xPos, yPos);
			std::cout << "New game";
			gotoXY(xPos, yPos + 1);
			std::cout << "Load game";
			
			setColor(10);
			gotoXY(xPos, yPos + 2);
			std::cout << "Setting";
			setColor(7);

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 4:
			gotoXY(xPos, yPos);
			std::cout << "New game";
			gotoXY(xPos, yPos + 1);
			std::cout << "Load game";
			gotoXY(xPos, yPos + 2);
			std::cout << "Setting";

			setColor(10);
			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			setColor(7);
			s = stateMove(state, sNum);
			break;
		case 5:
			return (mainChoice)(state - 1);
		}
	}
	std::cin.ignore(1000, '\n');
}

std::string Screen::saveMenu() {
	system("cls");
	Sleep(sleepTime);
	std::string dir, tmp;
	int isDir_Valid = 0;
	while (1) {
		gotoXY(xPos, yPos);
		std::cout << "Please input the name file you want to save your process !";
		gotoXY(xPos, yPos + 1);
		for (int i = 0; i <= dir.length() + 11; ++i) {
			std::cout << " ";
		}
		gotoXY(xPos, yPos + 1);
		std::cout << "Directory: ";
		dir.clear();
		dir += saveDir;
		std::getline(std::cin, tmp, '\n');
		dir += tmp;
		isDir_Valid = dir.find(".txt");
		if (isDir_Valid >= 0 && isDir_Valid < dir.length()) {

			std::ofstream fout(dir);
			if (fout.is_open()) {
				fout.close();
				return dir;
			}
		}
		else {
			setColor(12);
			gotoXY(xPos + 8, yPos + 4);
			std::cout << "Can not open " << dir;
			gotoXY(xPos+4, yPos + 5);
			std::cout << "Please recheck your directory !";
			setColor(7);
		}
	}
}

std::string Screen::loadChoice(int index) {
	std::string dir = loadDir;
	std::vector<std::string> load_list = read_directory(dir);
	if (load_list.size() > 0 && index >= 0 && index < load_list.size()) return load_list[index];
	else return {};
}

std::vector<std::string> Screen::loadList() {
	
	std::vector<std::string> loadList;
	std::string dir = loadChoice_Dir, tmp;
	
	std::ifstream fin(dir);
	if (!fin.is_open()) {
		std::cout << "Cannot open " << dir << std::endl;
		system("pause");
		return {};
	}
	while (!fin.eof()) {
		tmp.clear();
		std::getline(fin, tmp, '\n');
		loadList.push_back(tmp);
	}

	return loadList;
}

std::string Screen::loadMenu() {
	std::vector<std::string> load_list = read_directory("Data.txt");
	system("cls");
	Sleep(sleepTime);
	int state = 1, s = 1, sNum = 4;
	while (1)
	{
		switch (s)
		{
		case 1:
			setColor(10);
			gotoXY(xPos, yPos);
			std::cout << load_list[0];
			setColor(7);

			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1];
			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2];

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 2:
			gotoXY(xPos, yPos);
			std::cout << load_list[0];

			setColor(10);
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1];
			setColor(7);

			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2];

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 3:
			gotoXY(xPos, yPos);
			std::cout << load_list[0];
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1];

			setColor(10);
			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2];
			setColor(7);

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 4:
			gotoXY(xPos, yPos);
			std::cout << load_list[0];
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1];
			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2];

			setColor(10);
			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			setColor(7);
			s = stateMove(state, sNum);
			break;
		case 5:
			if (state == 4) return {};
			return loadChoice(state);
		}
	}
	std::cin.ignore(1000, '\n');
}


bool* Screen::constructor() {
	bool* res = new bool[20000];
	for (int i = 0; i < 20000; ++i) res[i] = 0;
	return res;
}

void Screen::destructor() {
	delete[] screen;
}

void Screen::setScreen(int i, int j, int c) {
	if (i * Width + j >= 20000 || i * Width + j < 0) {
		EXIT_ERROR("index screen out of range", 1);
	}
	if (!screen) EXIT_ERROR("Screen null", 1);
	screen[i * Width + j] = c;
}

bool Screen::isPixelNull(int i, int j) {
	return screen[i * Width + j] == 0;
}