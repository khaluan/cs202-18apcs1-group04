#include "ObstacleFactory.h"

ObstacleFactory::ObstacleFactory()
{
	//TODO: Load pattern of each of obstacle class here
	std::vector<std::string> patternDir{ "Truck.txt", "Car.txt", "Dinosaur.txt", "Bird.txt", "Light.txt"};
	for (unsigned i = 0; i < patternDir.size(); ++i) {
		std::vector<std::vector<std::vector<char>>> shape = readShape(patternDir[i]);
		pattern.push_back(shape);
	}
}

Obstacle * ObstacleFactory::getInstance(ObstacleType type, int x, int y)
{
	if (type == Truck) {
		ptr = new CTruck(x, y, pattern[Truck]);
	}
	else if (type == Car) {
		ptr = new CCar(x, y, pattern[Car]);
	}
	else if (type == Dinosaur) {
		ptr = new CDinosaur(x, y, pattern[Dinosaur]);
	}
	else if (type == Bird) {
		ptr = new CBird(x, y, pattern[Bird]);
	}
	else if (type == Light) {
		ptr = new TrafficLight(x, y, pattern[Light]);
	}
	else
		EXIT_ERROR("Wrong type initialization, type = " + char(type + '0'), -1);
	return ptr;
}

std::vector<std::vector<std::vector<char>>> ObstacleFactory::readShape(std::string & dir)
{
	std::string directory = "Data/" + dir;
	std::ifstream fin; 
	fin.open(directory);
	if (fin.is_open()) {
		int num, h, w; fin >> num >> h >> w;
		std::vector<std::vector<std::vector<char>>> tmp(num, std::vector<std::vector<char>>(h, std::vector<char>(w)));
		for (int k = 0; k < num; ++k)
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w; ++j) {
					int val; fin >> val;
					tmp[k][i][j] = char(val);
				}
		fin.close();
		return tmp;
	}
	else
		EXIT_ERROR("File at " + directory + " not found", -1);
}


ObstacleFactory::~ObstacleFactory()
{
}
