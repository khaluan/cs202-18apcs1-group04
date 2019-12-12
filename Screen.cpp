#include "Screen.h"
#include <Windows.h>


Screen::Screen() {
}


Screen::~Screen()
{
}


int Screen::stateMove(int& state, int n)
{

	while (1)
	{

		if ((GetAsyncKeyState(VK_UP) | GetAsyncKeyState('W')) & 0x8000) {
			Sleep(400);

			if (state > 1)
			{
				state -= 1;
			}
			else
			{
				state = n;
			}
			return state;
		}
		if ((GetAsyncKeyState(VK_LEFT) | GetAsyncKeyState('A')) & 0x8000) {
			Sleep(400);

			if (state > 1)
			{
				state -= 1;
			}
			else
			{
				state = n;
			}
			return state;
		}
		if ((GetAsyncKeyState(VK_DOWN) | GetAsyncKeyState('S')) & 0x8000) {
			Sleep(400);

			if (state < n)
			{
				state += 1;
			}
			else
			{
				state = 1;
			}
			return state;
		}
		if ((GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState('D')) & 0x8000) {
			Sleep(400);

			if (state < n)
			{
				state += 1;
			}
			else
			{
				state = 1;
			}
			return state;
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			Sleep(400);
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

pauseChoice Screen::pauseMenu() {
	system("cls");

	Sleep(sleepTime);
	int state = 1, s = 1, sNum = pauseChoice_list.size();
	gotoXY(xPos, yPos);
	std::cout << "Do you want to continue ?" << std::endl;
	while (1) {
		if (s <= sNum) {
			setColor(10);
			gotoXY(xPos, yPos + s);
			std::cout << pauseChoice_list[s - 1];
			setColor(7);

			for (int i = 0; i < sNum; ++i) {
				if (i == (s - 1)) continue;
				
				gotoXY(xPos, yPos + (i + 1));
				std::cout << pauseChoice_list[i];
			}
		}
		else return (pauseChoice)(state - 1);

		s = stateMove(state, sNum);
	}
}

mainChoice Screen::mainMenu()
{
	//tmp_changeScreen(-7, 20);
	system("cls");
	Sleep(sleepTime);
	int state = 1, s = 1, sNum = mainChoice_list.size();
	while (1)
	{
		if (s <= sNum) {
			setColor(10);
			gotoXY(xPos, yPos + s);
			std::cout << mainChoice_list[s - 1];
			setColor(7);
			for (int i = 0; i < sNum; ++i) {
				if (i == (s - 1)) continue;

				gotoXY(xPos, yPos + (i + 1));
				std::cout << mainChoice_list[i];
			}
		}
		else {
			//tmp_changeScreen(0,12);
			return (mainChoice)(state - 1);
		}
		s = stateMove(state, sNum);
	}
	std::cin.ignore(1000, '\n');
}

pauseChoice Screen::loseMenu()
{
	system("cls");

	Sleep(sleepTime);
	int state = 1, s = 1, sNum = pauseChoice_list.size();
	gotoXY(xPos, yPos);
	std::cout << "Do you want to replay this level ?" << std::endl;
	while (1) {
		if (s <= sNum) {
			setColor(10);
			gotoXY(xPos, yPos + s);
			std::cout << pauseChoice_list[s - 1];
			setColor(7);

			for (int i = 0; i < sNum; ++i) {
				if (i == (s - 1)) continue;

				gotoXY(xPos, yPos + (i + 1));
				std::cout << pauseChoice_list[i];
			}
		}
		else return (pauseChoice)(state - 1);

		s = stateMove(state, sNum);
	}
}

std::string Screen::saveMenu() {
	system("cls");
	Sleep(sleepTime);
	std::string dir, tmp;
	int isDir_Valid = 0;
	while (1) {
		gotoXY(xPos, yPos);
		std::cout << "Please choose the name file you want to save your process !" << std::endl;
		/*gotoXY(xPos, yPos + 1);
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
		}*/
		return loadMenu();
	}
}

std::string Screen::loadChoice(int index) {
	std::string dir = loadDir;
	std::vector<std::string> load_list = read_directory(dir);
	if (load_list.size() > 0 && index >= 0 && index < load_list.size()) return dir + load_list[index];
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
	std::vector<std::string> load_list = read_directory(loadDir);
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
			return loadChoice(state - 1);
		}
	}
	std::cin.ignore(1000, '\n');
}

/*	switch (s)
		{

		case 1:
			setColor(10);
			gotoXY(xPos, yPos+1);
			std::cout << "YES";
			setColor(7);

			gotoXY(xPos, yPos+2);
			std::cout << "No";

			s = stateMove(state, sNum);
			break;
		case 2:
			gotoXY(xPos, yPos+1);
			std::cout << "YES";

			setColor(10);
			gotoXY(xPos, yPos+2);
			std::cout << "No";
			setColor(7);


			s = stateMove(state, sNum);
			break;
		case 3:
			return (pauseChoice)(state - 1);
		}*/

//switch (s)
//{
//
//case 1:
//	setColor(10);
//	gotoXY(xPos, yPos);
//	std::cout << "New game";
//	setColor(7);
//
//	gotoXY(xPos, yPos + 1);
//	std::cout << "Load game";
//	gotoXY(xPos, yPos + 2);
//	std::cout << "Setting";
//
//	gotoXY(xPos, yPos + 5);
//	std::cout << "Exit";
//	s = stateMove(state, sNum);
//	break;
//case 2:
//	gotoXY(xPos, yPos);
//	std::cout << "New game";
//
//	setColor(10);
//	gotoXY(xPos, yPos + 1);
//	std::cout << "Load game";
//	setColor(7);
//
//	gotoXY(xPos, yPos + 2);
//	std::cout << "Setting";
//
//	gotoXY(xPos, yPos + 5);
//	std::cout << "Exit";
//	s = stateMove(state, sNum);
//	break;
//case 3:
//	gotoXY(xPos, yPos);
//	std::cout << "New game";
//	gotoXY(xPos, yPos + 1);
//	std::cout << "Load game";
//
//	setColor(10);
//	gotoXY(xPos, yPos + 2);
//	std::cout << "Setting";
//	setColor(7);
//
//	gotoXY(xPos, yPos + 5);
//	std::cout << "Exit";
//	s = stateMove(state, sNum);
//	break;
//case 4:
//	gotoXY(xPos, yPos);
//	std::cout << "New game";
//	gotoXY(xPos, yPos + 1);
//	std::cout << "Load game";
//	gotoXY(xPos, yPos + 2);
//	std::cout << "Setting";
//
//	setColor(10);
//	gotoXY(xPos, yPos + 5);
//	std::cout << "Exit";
//	setColor(7);
//	s = stateMove(state, sNum);
//	break;
//case 5:
//	return (mainChoice)(state - 1);
//}
