#include "Light.h"
#include "Support.h"
#include <iostream>

TrafficLight::TrafficLight(int x, int y) {
	shape = Cell(x, y);
}

void TrafficLight::change() {
	light = 1 - light;
	std::cout << light ? 'G' : 'R';
}

void TrafficLight::draw() {
	shape.draw();
	setColor(10);
	std::cout << light ? 'G' : 'R';
}