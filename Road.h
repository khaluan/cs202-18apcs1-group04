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
	Road(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	
	virtual void addObject(ObstacleType type);//This function add object to array of objects
	
	virtual void update();//Update position of all objects
	virtual void process(CPeople* player = nullptr);//Dont know what to do, = update + sleep
	
	static void CHANGE_END_TASK();
	static void CHANGE_PAUSE();

	void displayOutline();//This function is used to display 2 border of each lane
	virtual void display();
	void remove();

	direction getDirection();
	int getObjRow();

	virtual ~Road();
protected:
	static ObstacleFactory factory;//This factory produce the correspond instance of objects to the lane
	static bool END_TASK, PAUSE;
	int offset = 3;
	int maxObject = 5, objRow = 5, objectSpeed = 100;
	direction direct = Left;
	std::vector<Obstacle*> arr;
	ObstacleType type = Bird;
};
#endif // 

