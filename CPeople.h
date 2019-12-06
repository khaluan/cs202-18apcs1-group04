#ifndef CPEOPLE_H
#define CPEOPLE_H

#include "Screen.h"
#include "Cell.h"
#include "Obstacle.h"

class CPeople
{
public:
	CPeople();
	CPeople(const CPeople& src);
	CPeople(int x, int y);
	//void move(const char &c,const int & stepx, const int & stepy, const int &height, const int &width);
	std::vector<std::vector<std::vector<char>>> readShape(const std::string& dir);
	void move(const direction& d);

	bool isFinish();
	void turnState();//Comment code
	void display();
	//bool isImpact(const &CAnimal);
	//bool isImpact(const &CVehicle);
	void update();
	bool getState();
	int getX();
	int getY();
	void save(std::ofstream &fileGame);
	void load(std::ifstream &fileGame);
	void setXY(int x, int y);
	~CPeople();
private:
	Cell shape;
	bool state = true; //state true is alive, false is dead
};

#endif // !CPEOPLE_H
