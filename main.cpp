#include "Road.h"
#include "RoadVehicle.h"
#include <thread>

int main() {
	srand(time(NULL));
	ShowConsoleCursor(false);
	Road* p1, * p2, * p3, * p4, * p5;
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

	th5.join();
	th4.join();
	th3.join();
	th2.join();
	th1.join();
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;

	return 0;
}

//int main() {
//	std::cout << (int)'|';
//
//	return 0;
//}