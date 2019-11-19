#include "RoadAnimal.h"
#include "Screen.h"
#include "Support.h"

RoadAnimal::RoadAnimal() {
	_n = 3, _y = 5, speedAnimal = 1000, _direct = 2;
}

RoadAnimal::RoadAnimal(int n, int y, int sA, int direct) {
	_n = n; _y = y; speedAnimal = sA; _direct = direct;
	initBird();
}

void RoadAnimal::initBird() {
	CAnimal* p;
	for (int i = 0; i < _n; ++i) {
		p = new CBird;
		if (_direct == 2) {
			p->init(Width + i * 3, _y);
			arr.push_back(p);
		}
		if (_direct == 3) {
			p->init(1 - i * 3, _y);
			arr.push_back(p);
		}
	}

}

void RoadAnimal::Process() {
	while (1) {
		for (int i = 0; i < _n; ++i) arr[i]->move(_direct);
		Sleep(speedAnimal);
	}
}

RoadAnimal::~RoadAnimal() {
	for (unsigned int i = 0; i < arr.size(); ++i) {
		delete arr[i];
	}
}
