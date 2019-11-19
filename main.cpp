#include "Road.h"
#include "RoadVehicle.h"
#include <thread>

int main() {
	Road* p1, * p2, * p3, * p4, * p5, * p6, * p7, * p8;
	p1 = new Road(3, 5, Bird, 2, 100, Left);
	p2 = new RoadVehicle(3, 5, Bird, 5, 500, Right);
	p3 = new RoadVehicle(3, 5, Bird, 8, 300, Left);
	p4 = new RoadVehicle(3, 5, Bird, 11, 400, Right);
	p5 = new RoadVehicle(3, 5, Bird, 14, 200, Left);
	p6 = new RoadVehicle(3, 5, Bird, 17, 50, Right);
	p7 = new RoadVehicle(3, 5, Bird, 20, 20, Left);
	p8 = new RoadVehicle(3, 5, Bird, 23, 250, Right);

	std::thread Th1(&Road::process, p1);
	std::thread Th2(&Road::process, p2);
	std::thread Th3(&Road::process, p3);
	std::thread Th4(&Road::process, p4);
	std::thread Th5(&Road::process, p5);
	std::thread Th6(&Road::process, p6);
	std::thread Th7(&Road::process, p7);
	std::thread Th8(&Road::process, p8);

	Th1.join();
	Th2.join();
	Th3.join();
	Th4.join();
	Th5.join();
	Th6.join();
	Th7.join();
	Th8.join();

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;

	return 0;
}