#pragma once
#include "Screen.h"
#include "Cell.h"

class CPeople
{
public:
	CPeople();
	CPeople(int x, int y);
	//void move(const char &c,const int & stepx, const int & stepy, const int &height, const int &width);
	std::vector<std::vector<char>> readShape(const std::string& dir);
	void move(const int & stepx, const int & stepy);
	bool isFinish(const int &height);
	bool isDead();//Comment code
	void display();
	//bool isImpact(const &CAnimal);
	//bool isImpact(const &CVehicle);
	void update();
	~CPeople();
private:
	Cell shape;
	int x, y;
	bool state = true; //state true is alive, false is dead
};

