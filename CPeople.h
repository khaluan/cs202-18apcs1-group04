#pragma once
#include "Support.h"
class CPeople
{
public:
	CPeople() = default;
	CPeople(int _x, int _y);
	void move(const char &c, const int & stepx, const int & stepy, const int &height, const int &width);
	bool isFinish(const int &height);
	bool isDead();//Comment code
	void display();
	//bool isImpact(const &CAnimal);
	//bool isImpact(const &CVehicle);
	void update();
	~CPeople();
private:
	int x = 0, y = 0;
	bool state = true; //state true is alive, false is dead
};

