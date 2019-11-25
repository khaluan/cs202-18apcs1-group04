#include "Road.h"
#include "RoadVehicle.h"
#include "CPeople.h"
#include <thread>
#include "Screen.h"

int main() {
	srand(time(NULL));
	ShowConsoleCursor(false);
	Screen X;
	
	Road* p1, * p2, * p3, * p4, * p5;
	CPeople *tmp = new CPeople;
	p1 = new RoadVehicle(3, 5, Bird, 2, 100, Left);
	p2 = new RoadVehicle(3, 5, Bird, 6, 500, Right);
	p3 = new RoadVehicle(3, 5, Bird, 10, 200, Left);
	p4 = new RoadVehicle(3, 5, Bird, 14, 300, Right);
	p5 = new RoadVehicle(3, 5, Bird, 18, 250, Left);

	std::thread th1(&Road::process, p1);
	std::thread th2(&Road::process, p2);
	std::thread th3(&Road::process, p3);
	std::thread th4(&Road::process, p4);
	std::thread th5(&Road::process, p5);
//	std::thread th6(&CPeople::move, tmp);

	th5.detach();
	th4.detach();
	th3.detach();
	th2.detach();
	th1.detach();
	int choice;
	bool outState = false;

	/*while (1) {
		char c = _getch();
		if (c == 27) break;
		else tmp->move(c);
	}*/

	
	while (1) {
		char ch = _getch();
		if (ch == 27) {
			p5->temporaryStop();
			p4->temporaryStop();
			p3->temporaryStop();
			p2->temporaryStop();
			p1->temporaryStop();

			choice = X.pauseMenu();
			switch (choice) {
			case 1:
				p5->freeStop();
				p4->freeStop();
				p3->freeStop();
				p2->freeStop();
				p1->freeStop();
				break;
			case 2:
				p5->roadEnd();
				p4->roadEnd();
				p3->roadEnd();
				p2->roadEnd();
				p1->roadEnd();
				outState = true;
				break;
			}
			if (outState) break;
		}
		else if (ch == 'p') {
			p5->temporaryStop();
			p4->temporaryStop();
			p3->temporaryStop();
			p2->temporaryStop();
			p1->temporaryStop();

			while (1) {
				char c = _getch();
				if (c == 'p') break;
			}
			p5->freeStop();
			p4->freeStop();
			p3->freeStop();
			p2->freeStop();
			p1->freeStop();

		}
		else tmp->move(ch);
	}
	
	/*th5.join();
	th4.join();
	th3.join();
	th2.join();
	th1.join();*/
	
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete tmp;
	return 0;
}

//int main() {
//	std::cout << (int)'|';
//
//	return 0;
//}