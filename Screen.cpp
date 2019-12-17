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
				system("cls");
				difficultMenu();
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
			ConfigData::display(xPos, yPos);
		}
		s = stateMove(state, sNum);
	}
}

void Screen::difficultMenu()
{
	system("cls");
	gotoXY(xPos, yPos);
	std::cout << "Choose difficulty";
	const std::vector<std::string> option{ "Easy", "Normal", "Hard", "Expert", "Exit" };
	int state = 1, s = 1, sNum = option.size();
	while (true) {
		for (int i = 1; i <= option.size(); ++i) {
			if (i == s) {
				setColor(10);
			}
			gotoXY(xPos, yPos + i);
			std::cout << option[i - 1];
			if (i == s) {
				setColor(7);
			}
		}
		if (s == option.size() + 1) {
			if (state < option.size())
				ConfigData::difficulty = (state - 1) * 2;
			return;
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

void Screen::splashScreen() {
	system("cls");
	m.lock();
	std::string L1 = " @@@@@@@  @@@@@@@    @@@@@@    @@@@@@    @@@@@@   @@@  @@@  @@@   @@@@@@@@     @@@@@@@    @@@@@@    @@@@@@   @@@@@@@ ";
	std::string L2 = "@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@   @@@  @@@@ @@@  @@@@@@@@@     @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@";
	std::string L3 = "!@@       @@!  @@@  @@!  @@@  !@@       !@@       @@!  @@!@!@@@  !@@           @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@";
	std::string L4 = "!@!       !@!  @!@  !@!  @!@  !@!       !@!       !@!  !@!!@!@!  !@!           !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@";
	std::string L5 = "!@!       @!@!!@!   @!@  !@!  !!@@!!    !!@@!!    !!@  @!@ !!@!  !@! @!@!@     @!@!!@!   @!@  !@!  @!@!@!@!  @!@  !@!";
	std::string L6 = "!!!       !!@!@!    !@!  !!!   !!@!!!    !!@!!!   !!!  !@!  !!!  !!! !!@!!     !!@!@!    !@!  !!!  !!!@!!!!  !@!  !!!";
	std::string L7 = ":!!       !!: :!!   !!:  !!!       !:!       !:!  !!:  !!:  !!!  :!!   !!:     !!: :!!   !!:  !!!  !!:  !!!  !!:  !!!";
	std::string L8 = ":!:       :!:  !:!  :!:  !:!      !:!       !:!   :!:  :!:  !:!  :!:   !::     :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!";
	std::string L9 = " ::: :::  ::   :::  ::::: ::  :::: ::   :::: ::    ::   ::   ::   ::: ::::     ::   :::  ::::: ::  ::   :::   :::: ::";
	std::string L14 = " :: :: :   :   : :   : :  :   :: : :    :: : :    :    ::    :    :: :: :       :   : :   : :  :    :   : :  :: :  : ";

	std::string L10 = "   - PHAM KHA LUAN - ";
	std::string L11 = "   - LE HOANG NHAN - ";
	std::string L12 = " - HOANG NGUYEN KHOI - ";

	// Show "about screen"
	gotoXY(50, 20);
	std::cout << L10;
	animation(1, 800);

	gotoXY(50, 21);
	std::cout << L11;
	animation(2, 800);

	gotoXY(50, 22);
	std::cout << L12;
	animation(3, 800);

	// Make text color effect
	gotoXY(7, 5);
	std::cout << L1;
	animation(0, 50);

	gotoXY(7, 6);
	std::cout << L2;
	animation(1, 200);

	gotoXY(7, 7);
	std::cout << L3;
	animation(3, 200);

	gotoXY(7, 8);
	std::cout << L4;
	animation(5, 200);

	gotoXY(7, 9);
	std::cout << L5;
	animation(7, 200);

	gotoXY(7, 10);
	std::cout << L6;
	animation(9, 200);

	gotoXY(7, 11);
	std::cout << L7;
	animation(0, 200);

	gotoXY(7, 12);
	std::cout << L14;
	animation(0, 200);

	// Make background color effect
	for (int i = 500; i > 0; i -= 250)
	{
		system("color 1");
		Sleep(70);
		system("color 2");
		Sleep(70);
		system("color 3");
		Sleep(70);
		system("color 4");
		Sleep(70);
		system("color 5");
		Sleep(70);
		system("color 6");
		Sleep(70);
		system("color 7");
		Sleep(70);
		system("color 8");
		Sleep(70);
	}

	system("color e");

	animation(0, 500);

	gotoXY(50, 25);
	system("pause");
	m.unlock();
	system("cls");
}

void Screen::animation(int m, int n)
{
	if (m == 1) system("color 1");
	if (m == 2) system("color 2");
	if (m == 3) system("color 3");
	if (m == 4) system("color 4");
	if (m == 5) system("color 5");
	if (m == 6) system("color 6");
	if (m == 7) system("color 7");
	if (m == 8) system("color 8");
	if (m == 9) system("color 9");
	Sleep(n);
}

void Screen::saveScreen()
{
	system("cls");
	//string s1 = "SAVING...";
	std::string L1 = "  SSSSS    A  VV      VV IIIIII  NN   NN   GGGGGG    ";
	std::string L2 = " SSSS     A A  VVV  VVV    II    NNN  NN  GGGGG     ";
	std::string L3 = "	SSSS    AAAAA  VVVVVV 	  II    NN N NN GGGGG  GGG";
	std::string L4 = "	 SSSS  AA   AA  VVVV 	  II    NN  NNN  GGGGG  G	";
	std::string L5 = " SSSSS AA     AA  VV     IIIIII  NN   NN   GGGGGG	";
	std::string L6 = " ";
	
	gotoXY(20, 5);
	std::cout << L1;
	animation(0, 50);

	gotoXY(20, 6);
	std::cout << L2;
	animation(1, 200);

	gotoXY(20, 7);
	std::cout << L3;
	animation(3, 200);

	gotoXY(20, 8);
	std::cout << L4;
	animation(5, 200);

	gotoXY(7, 9);
	std::cout << L5;
	animation(7, 200);

	gotoXY(20, 10);
	std::cout << L6;
	animation(9, 200);

	setColor(7);
	Sleep(1000);


	system("cls");
	std::cout << "COMPLETED!";
	Sleep(1000);
}

void Screen::losescreen()
{
	system("cls");
	std::string L1 = "  uu      uu          LL           oooooo       sssssss   eeeeeeee    ";
	std::string L2 = "  uu      uu          LL          oo    oo     sss        ee          ";
	std::string L3 = "  uu      uu          LL         oo      oo    ssss       ee          ";
	std::string L4 = "  uu      uu          LL         oo      oo      ssss     eeeeee      ";
	std::string L5 = "  uu      uu          LL          oo    oo          sss   ee          ";
	std::string L6 = "   uuuuuuuu           LLLLLLLLL    oooooo      sssssss    eeeeeeee    ";
	std::string L7 = " ";


	gotoXY(20, 5);
	std::cout << L1;
	animation(0, 50);

	gotoXY(20, 6);
	std::cout << L2;
	animation(1, 200);

	gotoXY(20, 7);
	std::cout << L3;
	animation(3, 200);

	gotoXY(20, 8);
	std::cout << L4;
	animation(5, 200);

	gotoXY(20, 9);
	std::cout << L5;
	animation(7, 200);

	gotoXY(20, 10);
	std::cout << L6;
	animation(9, 200);

	setColor(7);
	Sleep(1000);

	system("cls");
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

void ConfigData::display(int xPos, int yPos)
{
	gotoXY(xPos + 15, yPos + 1);
	if (soundOn)
		std::cout << "ON";
	else
		std::cout << "OFF";

	gotoXY(xPos + 15, yPos + 2);
	std::cout << playerName;

	gotoXY(xPos + 15, yPos + 3);
	std::vector<std::string> diff { "Easy", "Normal", "Hard", "Expert" };
	std::cout << diff[difficulty / 2];
}
