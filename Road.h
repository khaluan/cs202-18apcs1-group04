#ifndef __ROAD_H__
#define __ROAD_H__
#include "ObstacleFactory.h"
#include "Obstacle.h"
#include "Cell.h"
#include "Support.h"
#include "Screen.h"
#include <vector>
class Road
{
public:
	Road();
	Road(int offset, int maxObject, ObstacleType type, int objRow, int objectSpeed, direction direct);
	
	void addObject(ObstacleType type);//This function add object to array of objects
	
	virtual void update();//Update position of all objects
	virtual void process();//Dont know what to do, = update + sleep

	void displayOutline();//This function is used to display 2 border of each lane
	virtual void display();
	void remove();

	direction getDirection();
	int getObjRow();

	virtual ~Road();
private:
	int offset = 3;
	int maxObject, objRow, objectSpeed = 1000;
	direction direct;
	std::vector<Obstacle*> arr;
	ObstacleType type;
	static ObstacleFactory factory;//This factory produce the correspond instance of objects to the lane
};
#endif // 

