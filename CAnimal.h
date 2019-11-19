#ifndef CANIMAL_H
#define CANIMAL_H

#include "Cell.h"

class CAnimal {
public:
	void init(int x, int y);
	virtual void inputShape() = 0;
	void move(int direct); //0: up 1: down 2: left 3: right
protected:
	Cell shape;
};

#endif
