#ifndef ROADANIMAL_H
#define ROADANIMAL_H

#include "CBird.h"
#include <vector>

class RoadAnimal {
public:
	RoadAnimal();
	RoadAnimal(int n, int y, int sA, int direct);
	~RoadAnimal();
	void initBird();
	void Process();
private:
	int _n , _y , speedAnimal ,  _direct;
	std::vector <CAnimal*> arr;
};

#endif // !ROADVEHICLE_H
