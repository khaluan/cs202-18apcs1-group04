#include "Level.h"
std::vector<std::vector<bool>> Level::screen = std::vector<std::vector<bool>>(Height, std::vector<bool>(Width, 0));

Level::Level(const Level & src)
{
	this->arrRoad = src.arrRoad;
	this->player = src.player;
	this->level = src.level;
	this->sizeArr = src.sizeArr;
}

Level & Level::operator=(Level src)
{
	this->arrRoad.swap(src.arrRoad);
	std::swap(this->player, src.player);
	std::swap(this->level, src.level);
	std::swap(this->sizeArr, src.sizeArr);
	return *this;
}

Level::Level(int level)
{
	this->level = level;
	// int offset,int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct
	int typeRoad;
	sizeArr = random(max(3, level / 4 + 3), min(level / 4 + 4, 5));
	arrRoad.resize(sizeArr);
	for (int i = 1; i <= sizeArr; ++i) {
		typeRoad = random(0, 1);
		if (typeRoad == 0) {
			switch ((level + ConfigData::difficulty) / 3) {
			case 0:
				arrRoad[i - 1] = new Road(3, random(2, 3), ObstacleType(random(2, 3)), 2 + 6 * i, random(175, 200), direction(random(2, 3)));
				break;
			case 1:
				arrRoad[i - 1] = new Road(3, random(3, 4), ObstacleType(random(2, 3)), 2 + 6 * i, random(150, 175), direction(random(2, 3)));
				break;
			case 2:
				arrRoad[i - 1] = new Road(3, random(4, 5), ObstacleType(random(2, 3)), 2 + 6 * i, random(125, 150), direction(random(2, 3)));
				break;
			case 3:
				arrRoad[i - 1] = new Road(3, random(5, 6), ObstacleType(random(2, 3)), 2 + 6 * i, random(100, 150), direction(random(2, 3)));
				break;
			case 4:
				arrRoad[i - 1] = new Road(3, 7, ObstacleType(random(2, 3)), 2 + 6 * i, random(50, 60), direction(random(2, 3)));
				break;
			default:
				arrRoad[i - 1] = new Road(3, 8, ObstacleType(random(3, 3)), 2 + 6 * i, random(25, 50), direction(random(2, 3)));
				break;
			}
		}
		else if (typeRoad == 1) {
			switch ((level + ConfigData::difficulty) / 3) {
			case 0:
				arrRoad[i - 1] = new RoadVehicle(3, random(2, 3), ObstacleType(random(0, 1)), 2 + 6 * i, random(175, 200), direction(random(2, 3)));
				break;
			case 1:
				arrRoad[i - 1] = new RoadVehicle(3, random(3, 4), ObstacleType(random(0, 1)), 2 + 6 * i, random(150, 175), direction(random(2, 3)));
				break;
			case 2:
				arrRoad[i - 1] = new RoadVehicle(3, random(4, 5), ObstacleType(random(0, 1)), 2 + 6 * i, random(125, 150), direction(random(2, 3)));
				break;
			case 3:
				arrRoad[i - 1] = new RoadVehicle(3, random(5, 6), ObstacleType(random(0, 1)), 2 + 6 * i, random(100, 150), direction(random(2, 3)));
				break;
			case 4:
				arrRoad[i - 1] = new RoadVehicle(3, 7, ObstacleType(random(0, 1)), 2 + 6 * i, random(50, 60), direction(random(2, 3)));
				break;
			default:
				arrRoad[i - 1] = new RoadVehicle(3, 8, ObstacleType(random(0, 1)), 2 + 6 * i, random(25, 50), direction(random(2, 3)));
				break;
			}
		}
		else EXIT_ERROR("Level::Level()", -1);
	}
	player = new CPeople(85, 6 * sizeArr + 8);
}

int Level::getLevel()
{
	return level;
}

void Level::saveGame(const std::string & gameName)
{
	if (gameName == "")
		return;
	std::ofstream fileSave;
	fileSave.open(gameName, std::ios_base::binary);
	if (fileSave.is_open()) {
		int tmp = ConfigData::playerName.size();
		fileSave.write((char*)&tmp, sizeof(tmp));
		fileSave.write(ConfigData::playerName.c_str(), tmp);
		auto time = std::chrono::system_clock::now();
		std::time_t save_time = std::chrono::system_clock::to_time_t(time) + 25200;
		//fileSave << save_time << std::endl;
		fileSave.write((char*)&save_time, sizeof(save_time));
		//fileSave << level << std::endl;
		//fileSave << sizeArr << std::endl;
		fileSave.write((char*)&level, sizeof(level));
		fileSave.write((char*)&sizeArr, sizeof(level));
		for (int i = 0; i < sizeArr; ++i)
			arrRoad[i]->save(fileSave);
		player->save(fileSave);
		fileSave.close();
	}
	else
		EXIT_ERROR("Cant open file to save", -1);
}

void Level::loadGame(const std::string & gameName)
{
	std::ifstream gameFile;
	gameFile.open(gameName, std::ios_base::binary);
	if (gameFile.is_open()) {
		int tmp;
		gameFile.read((char*)&tmp, sizeof(tmp));
		if (tmp == 0) {
			EXIT_ERROR("This slot is empty", -2);
			return;
		}
		char* str;
		str = new char[tmp + 1];
		gameFile.read(str, tmp);
		str[tmp] = '\0';
		ConfigData::playerName = std::string(str);
		delete str;
		std::time_t time;
		//gameFile >> time;
		gameFile.read((char*)&time, sizeof(time_t));
		//gameFile >> level >> sizeArr;
		gameFile.read((char*)&level, sizeof(level));
		gameFile.read((char*)&sizeArr, sizeof(sizeArr));
		arrRoad.resize(sizeArr);
		for (int i = 0; i < sizeArr; ++i) {
			int type; 
			//gameFile >> type;
			gameFile.read((char*)&type, sizeof(type));
			if (type == 0)
				arrRoad[i] = new Road;
			else
				arrRoad[i] = new RoadVehicle;
			arrRoad[i]->load(gameFile);
		}
		player = new CPeople;
		player->load(gameFile);
		for (int i = 0; i < arrRoad.size(); ++i)
			arrRoad[i]->displayOutline();
		gameFile.close();
	}
	else
		EXIT_ERROR("Can open file " + gameName + " to load game", -1);
}

void Level::drawGame() {
	m.lock();
	system("cls");
	instruction();
	setColor(11);
	gotoXY(225, 47);
	std::cout << "LEVEL " << level;

	std::string time, date, now = __TIMESTAMP__;
	time = now.substr(11, 8);
	date = now.substr(0, 11);
	date += now.substr(20, 4);
	time += " " + date;

	gotoXY(5, 47);
	std::cout << "Player: " << ConfigData::playerName<<"      "<< date;
	setColor(7);

	player->display();

	for (int i = 0; i < sizeArr; ++i) {
		arrRoad[i]->displayOutline();
		//arrRoad[i]->display();
	}
	m.unlock();
}

levelState Level::process() {
	//drawGame();
	std::vector<std::thread> th = createRoad();
	if (Road::isPause())
		Road::CHANGE_PAUSE();
	if (Road::isExit())
		Road::CHANGE_EXIT();
	for (int i = 0; i < sizeArr; ++i)
		th[i] = std::thread(&Road::process, arrRoad[i], player);
	while (player->getState() && !player->isFinish()) {
		if ((GetAsyncKeyState(VK_UP) | GetAsyncKeyState('W')) & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			player->move(Up);
		}

		if ((GetAsyncKeyState(VK_DOWN) | GetAsyncKeyState('S')) & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			player->move(Down);
		}

		if ((GetAsyncKeyState(VK_LEFT) | GetAsyncKeyState('A')) & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			player->move(Left);
		}

		if ((GetAsyncKeyState(VK_RIGHT) | GetAsyncKeyState('D')) & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			player->move(Right);
		}

		if (GetAsyncKeyState('P') & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			Road::CHANGE_EXIT();
			for (int i = 0; i < sizeArr; ++i) {
				th[i].join();
			}
			return PAUSEGAME;
		}
		if (GetAsyncKeyState('L') & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			Road::CHANGE_EXIT();
			for (int i = 0; i < sizeArr; ++i) {
				th[i].join();
			}
			return SAVEGAME;
		}
		if (GetAsyncKeyState('Q') & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			std::ofstream fout;
			fout.open("Log.rtf");
			log(fout);
			fout.close();
		}
		if (GetAsyncKeyState('T') & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			Road::CHANGE_EXIT();
			for (int i = 0; i < sizeArr; ++i) {
				th[i].join();
			}
			return LOAD;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Sleep(SLEEP_TIME_BETWEEN_SCREEN);
			break;
		}
	}
	Road::CHANGE_EXIT();
	for (int i = 0; i < sizeArr; ++i) {
		th[i].join();
	}
	if (player->isFinish())
		return WIN;
	else if (!player->getState())
		return LOSE;
	else
		return EXIT;
}

std::vector<std::thread> Level::createRoad() {
	return std::vector<std::thread>(sizeArr);
}

void Level::deallocateRoad(std::vector<std::thread> &th) {
	
}

void Level::log(std::ofstream & fout)
{
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j)
			fout << screen[i][j] << " ";
		fout << std::endl;
	}
}

bool Level::isPixelNull(int i, int j) {
	//if (j <= 0 || j >= Width || i < 0 || i >= Height)
	//	std::cerr << "Bum";
	return !screen[i][j];
}

void Level::setScreen(int i, int j, bool c) {
	if (i < 0 || i > Height || j < 0 || j > Width) {
		EXIT_ERROR("index screen out of range", 1);
	}
	screen[i][j] = c;
}

void Level::resetScreen()
{
	for (int i = 0; i < Height; ++i)
		for (int j = 0; j < Width; ++j)
			screen[i][j] = 0;
}

Level::~Level()
{
	resetScreen();
	delete player;
}
