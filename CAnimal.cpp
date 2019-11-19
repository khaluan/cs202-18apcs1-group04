#include "CAnimal.h"

void CAnimal::init(int x, int y) {
	shape.init(x, y);
}

void CAnimal::move(int direct) {
	shape.move(direct);
}