#ifndef CPEOPLE_H
#define CPEOPLE_H

#include "Screen.h"
#include "Cell.h"
#include "Obstacle.h"

class CPeople
{
public:
	CPeople();
	CPeople(int x, int y);
	//void move(const char &c,const int & stepx, const int & stepy, const int &height, const int &width);
	std::vector<std::vector<char>> readShape(const std::string& dir);
	void move(const direction& d);

	void CheckCrash(Obstacle& a);
	bool isFinish(const int &height);
	bool isDead();//Comment code
	void display();
	//bool isImpact(const &CAnimal);
	//bool isImpact(const &CVehicle);
	void update();
	bool getState();
	int getX();
	int getY();
	~CPeople();
private:
	Cell shape;
	int x, y, stepX = 4, stepY = 4;
	bool state = true; //state true is alive, false is dead
};

#endif // !CPEOPLE_H
