#ifndef CVEHICLE_H
#define CVEHICLE_H

#include "Cell.h"

class CVehicle {
public:
	CVehicle(int x, int y);
	void move(int direct); //0: up 1: down 2: left 3: right
private:
	Cell shape;
};

#endif