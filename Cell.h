#ifndef CELL_H
#define CELL_H

#include <fstream>

class Cell{
public:
	Cell() = default;
	Cell(int x, int y);
	void input(std::ifstream& fin);
	void draw();
	void remove(); 
	void move(int direct); //0: up 1: down 2:left 3:right
private:
	int _x = 1, _y = 1;
	int w = 3, h = 3;
	char a[3][3];
};

#endif // !CELL_H
