#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

#include "Obstacle.h"
#include "CBird.h"
#include "Truck.h"
#include "Car.h"
#include "Dinosaur.h"
#include "Support.h"
#include "Light.h"

enum ObstacleType
{
	Truck,
	Car,
	Dinosaur,
	Bird,
	Light
};

class ObstacleFactory
{
public:
	ObstacleFactory();
	Obstacle* getInstance(ObstacleType type, int x, int y);
	std::vector<std::vector<char>> readShape(std::string& dir);
	~ObstacleFactory();
private:
	std::vector < std::vector<std::vector<char>> >pattern;
	Obstacle * ptr = nullptr;
};

#endif // !OBSTACLEFACTORY_H
