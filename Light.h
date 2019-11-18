#ifndef LIGHT_H
#define LIGHT_H

#include "Cell.h"

class TrafficLight {
public:
	TrafficLight() = default;
	TrafficLight(int x, int y);
	void draw();
	void change();
private:
	Cell shape;
	bool light = 0; //0 red 1 green
};

#endif // !LIGHT_H
