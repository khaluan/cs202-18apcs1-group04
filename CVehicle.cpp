#include "CVehicle.h"

CVehicle::CVehicle(int x, int y) {
	shape = Cell(x, y);


}

void CVehicle::move(int direct) {
	shape.move(direct);
}