#include "Support.h"
int main() {
	CPeople p(0, 3);
	Road r(1, 6);
	Road r1(6, 11);
	r.display(30, 100);
	r1.display(30, 100);
	while (true) {
		char c = _getch();
		p.move(c, 5, 5, 30, 100);
		p.display();
	}
	return 0;
}