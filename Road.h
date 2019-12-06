#ifndef __ROAD_H__
#define __ROAD_H__
#include "ObstacleFactory.h"
#include "Obstacle.h"
#include "Cell.h"
#include "Support.h"
#include "Screen.h"
#include "CPeople.h"
#include <vector>
class Road
{
public:
	Road();
	virtual ~Road();
	Road(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	
	virtual void addObject(ObstacleType type);//This function add object to array of objects
	
	virtual void update(CPeople* a);//Update position of all objects
	virtual void process(CPeople* a);//Dont know what to do, = update + sleep
	
	static void CHANGE_PAUSE();
	static void CHANGE_EXIT();

	void displayOutline();//This function is used to display 2 border of each lane
	virtual void display();
	void remove();

	virtual void save(std::ofstream& gameFile);
	void saveHelper(std::ofstream& gameFile);
	virtual void load(std::ifstream &gameFile);

	static bool isPause();
	static bool isExit();
	direction getDirection();
	int getObjRow();
protected:
	static ObstacleFactory factory;//This factory produce the correspond instance of objects to the lane
	static bool PAUSE, EXIT;
	int offset = 1;

	int maxObject = 5, objRow = 5, objectSpeed = 100;
	direction direct = Left;
	std::vector<Obstacle*> arr;
	ObstacleType type = Bird;
};
#endif // 

