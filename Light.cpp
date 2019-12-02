#include "Light.h"
#include "Support.h"
#include <iostream>

TrafficLight::TrafficLight(int x, int y, std::vector<std::vector<std::vector<char>>> shape):Obstacle(x, y, shape) {}
