#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "Road.h"
#include "CPeople.h"
#include "RoadVehicle.h"
#include <ctime>
enum levelState
{
	WIN,
	SAVEGAME,
	LOAD,
	PAUSEGAME,
	EXIT,
	LOSE
};

class Level
{
public:
	Level() = default;
	Level(const Level& src);
	Level& operator=(Level src);
	Level(int level);

	int getLevel();

	void saveGame(const std::string& gameName);
	void loadGame(const std::string& gameName);
	levelState process();
	static void setScreen(int i, int j, bool c);
	static bool isPixelNull(int i, int j);
	void log(std::ofstream &fout);
	void drawGame();

	std::vector<std::thread> createRoad();
	void deallocateRoad(std::vector<std::thread> &th);

	void resetScreen();
	~Level();
private:
	const int SLEEP_TIME_BETWEEN_SCREEN = 100;
	std::vector<Road*> arrRoad;
	CPeople* player = nullptr;
	int level, sizeArr;
	static std::vector<std::vector<bool>> screen;
	//std::vector<std::thread> th; //thread controll
};

#endif // !__LEVEL_H__



