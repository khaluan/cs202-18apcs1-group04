#ifndef CELL_H
#define CELL_H
#include <fstream>
#include <vector>

enum direction
{
	Up, 
	Down,
	Left, 
	Right
};

class Cell{
public:
	Cell() = default;
	Cell(int x, int y, std::vector<std::vector<char>> shape);
	Cell(int x, int y);
	void input(std::ifstream& fin);
	void draw();
	void remove(); 
	void move(direction d); //0: up 1: down 2:left 3:right
private:
	int x = 1, y = 1;
	int w = 3, h = 3;
	std::vector<std::vector<char>> a;
};

#endif // !CELL_H
