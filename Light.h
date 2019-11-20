#ifndef LIGHT_H
#define LIGHT_H

#include "Cell.h"
#include "Obstacle.h"

class TrafficLight: public Obstacle {
public:
	TrafficLight() = default;
	TrafficLight(int x, int y, std::vector<std::vector<char>> shape);private:
};

#endif // !LIGHT_H
