#include "Road.h"

int main() {
	Road r(4, 5, Bird, 10, 3000, Right);
	r.displayOutline();
	while (true) {
		r.update();
		r.display();
		Sleep(600);
		r.remove();
	}
	return 0;
}