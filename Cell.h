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
	Cell(int x, int y, std::vector<std::vector<std::vector<char>>> shape);
	bool draw(bool isLight = false);
	void remove(); 
	bool move(direction d, int stepX = 3, int stepY = 6); //0: up 1: down 2:left 3:right
	void changeColor(bool color);
	int getX();
	int getY();

	bool operator==(const Cell &a);
	void save(std::ofstream &fileGame);
	void load(std::ifstream &fileGame);
private:
	int x = 4, y = 4;
	int w = 5, h = 5;
	int idPic = 0;
	std::vector<std::vector<std::vector<char>>> a;
};

//class Cell {
//public:
//	Cell() = default;
//	Cell(int x, int y, std::vector<std::vector<char>> shape);
//	Cell(int x, int y);
//	void init(int x, int y);
//	void input(std::ifstream& fin);
//	void draw(bool isLight = false);
//	void remove();
//	void move(direction d); //0: up 1: down 2:left 3:right
//	void changeColor(bool color);
//private:
//	int x = 1, y = 1;
//	int w = 3, h = 3;
//	std::vector<std::vector<char>> a;
//};

#endif // !CELL_H
