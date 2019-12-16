#include "Screen.h"
#include <Windows.h>

std::string ConfigData::playerName = "Default";
int ConfigData::difficulty = 0;
bool ConfigData::soundOn = true;

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
	std::cin.ignore(100, '\n');
	std::getline(std::cin, name, '\n');
	playerInfo.push_back(name);
	playerInfo.push_back(time);
	return playerInfo;
}

pauseChoice Screen::pauseMenu() {
	//initScreen(24);
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
	//initScreen(24);
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
		else return (mainChoice)(state - 1);
		s = stateMove(state, sNum);
	}
	std::cin.ignore(1000, '\n');
}

pauseChoice Screen::loseMenu()
{
	//initScreen(24);
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

std::vector<std::vector<std::string>> Screen::loadList() {
	
	std::vector<std::string> loadChoice = read_directory(loadDir);
	std::vector<std::vector<std::string>> loadList(loadChoice.size(), std::vector<std::string>());
	std::string name, date, level;
	int size = 0;
	
	std::ifstream fin;
	for (int i = 0; i < loadChoice.size(); ++i) {
		fin.open(loadDir + loadChoice[i], std::ios::binary);
		if (!fin.is_open()) {
			std::cout << "Cannot open " << loadDir + loadChoice[i] << std::endl;
			system("pause");
			return {};
		}
		fin.read((char*)&size, 4);
		if (size == 0) {
			name = "";
			date = "";
			level = "";
		}
		else {
			char buffer[100];
			fin.read(buffer, size);
			buffer[size] = '\0';
			name = std::string(buffer);
			time_t time;
			fin.read((char*)&time, sizeof(time));
			std::tm* t = std::gmtime(&time);
			std::stringstream ss;
			ss << std::put_time(t, "%Y-%m-%d %I:%M:%S %p");
			date = ss.str();
			ss.str("");
			int l;
			fin.read((char*)&l, sizeof(l));
			ss << l;
			ss >> level;
			level = "Level " + level;
		}
		fin.close();
		loadList[i].push_back(name);
		loadList[i].push_back(level);
		loadList[i].push_back(date);
	}
	return loadList;
}

void Screen::settingMenu()
{
	gotoXY(xPos, yPos);
	int s = 1, sNum = settingChoice_list.size(), state = 1;
	std::cout << "Setting" << std::endl;
	while (1) {
		if (s > sNum) {
			switch (state) {
			case 1: {
				if (!ConfigData::soundOn) {
					PlaySound(TEXT("Data/GamesSong.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				else {
					PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);
				}
				ConfigData::soundOn = !ConfigData::soundOn;
				s = 1;
				break;
			}
			case 2: {
				auto res = inputPlayer_Menu();// Name and timestamp
				ConfigData::playerName = res[0];
				Sleep(200);
				s = 2;
				break;
			}
			case 3: {
				/*TODO*/
				s = 3;
			}
			default:
				return;
			}
		}
		system("cls");
		setColor(10);
		gotoXY(xPos, yPos + s);
		std::cout << settingChoice_list[s - 1];
		setColor(7);

		for (int i = 0; i < sNum; ++i) {
			if (i == (s - 1)) continue;

			gotoXY(xPos, yPos + (i + 1));
			std::cout << settingChoice_list[i];
		}
		s = stateMove(state, sNum);
	}
}

std::string Screen::loadMenu() {
	//initScreen(24);
	//std::vector<std::string> load_list = read_directory(loadDir);
	std::vector < std::vector<std::string> > load_list = loadList();
	system("cls");
	Sleep(sleepTime);
	for (int i = 0; i < load_list.size(); ++i) {
		if (load_list[i][0] == "") load_list[i][0] = "Empty slot";
	}
	int state = 1, s = 1, sNum = 4;
	while (true) {
		for (int i = 1; i <= load_list.size(); ++i) {
			if (i == s) {
				setColor(10);
			}
			for (int j = 0; j < load_list[i - 1].size(); ++j) {
				gotoXY(xPos + 20 * j, yPos + i);
				std::cout << load_list[i - 1][j];
			}
			if (i == s) {
				setColor(7);
			}
		}

		if (s == load_list.size() + 1)
			setColor(10);
		gotoXY(xPos, yPos + 5);
		std::cout << "Exit";
		if (s == load_list.size() + 1)
			setColor(7);
		if (s == load_list.size() + 2) {
			if (state == load_list.size() + 1)
				return { };
			else
				return loadChoice(state - 1);
		}

		s = stateMove(state, sNum);
	}
	/*while (1)
	{
		switch (s)
		{
		case 1:
			setColor(10);
			gotoXY(xPos, yPos);
			std::cout << load_list[0][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[0][1];
			setColor(7);

			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1][0];
			gotoXY(xPos + 15, yPos + 1);
			std::cout << load_list[1][1];

			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2][0];
			gotoXY(xPos + 15, yPos + 2);
			std::cout << load_list[2][1];

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 2:
			gotoXY(xPos, yPos);
			std::cout << load_list[0][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[0][1];

			setColor(10);
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1][0];
			gotoXY(xPos + 15, yPos + 1);
			std::cout << load_list[1][1];
			setColor(7);

			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2][0];
			gotoXY(xPos + 15, yPos + 2);
			std::cout << load_list[2][1];

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 3:
			gotoXY(xPos, yPos);
			std::cout << load_list[0][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[0][1];
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1][0];
			gotoXY(xPos + 15, yPos + 1);
			std::cout << load_list[1][1];

			setColor(10);
			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2][0];
			gotoXY(xPos + 15, yPos + 2);
			std::cout << load_list[2][1];
			setColor(7);

			gotoXY(xPos, yPos + 5);
			std::cout << "Exit";
			s = stateMove(state, sNum);
			break;
		case 4:
			gotoXY(xPos, yPos);
			std::cout << load_list[0][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[0][1];
			gotoXY(xPos, yPos + 1);
			std::cout << load_list[1][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[1][1];
			gotoXY(xPos, yPos + 2);
			std::cout << load_list[2][0];
			gotoXY(xPos + 15, yPos);
			std::cout << load_list[2][1];

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
	}*/
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

void ConfigData::load(){
	std::ifstream fin;
	fin.open("Data/config.dat", std::ios_base::binary);
	if (fin.is_open()) {
		int size; 
		fin.read((char*)&size, sizeof(size));
		char * tmp;
		tmp = new char[size + 1];
		tmp[size] = '\0';
		fin.read(tmp, size);
		playerName = std::string(tmp);

		fin.read((char*)&ConfigData::soundOn, sizeof(ConfigData::soundOn));
		fin.read((char*)&ConfigData::difficulty, sizeof(ConfigData::difficulty));
		fin.close();	
	}
	else
		save(true);
}

void ConfigData::save(bool Default)
{
	std::ofstream fout;
	fout.open("Data/config.dat");
	if (Default) {
		char tmp[] = "Default";
		int size = strlen(tmp);
		fout.write((char*)&size, sizeof(size));
		fout.write(tmp, size);
		bool soundOn = true;
		fout.write((char*)&soundOn, sizeof(soundOn));
		int dif = 0;
		fout.write((char*)&dif, sizeof(dif));
	}
	else {
		int size = ConfigData::playerName.size();
		fout.write((char*)&size, sizeof(size));
		fout.write(ConfigData::playerName.c_str(), size);
		fout.write((char*)&ConfigData::soundOn, sizeof(ConfigData::soundOn));
		fout.write((char*)&ConfigData::difficulty, sizeof(ConfigData::difficulty));
	}
}
