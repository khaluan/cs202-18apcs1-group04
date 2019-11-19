#include "Cell.h"
#include "Support.h"
#include "Screen.h"
#include <iostream>

Cell::Cell(int x, int y, std::vector<std::vector<char>> shape) {
	this->x = x; this->y = y;
	this->a = shape;
	this->h = shape.size();
	this->w = shape[0].size();
}

Cell::Cell(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Cell::input(std::ifstream & fin)
{
	//TODO: 
}

void Cell::draw() {
	if (x < 0 || x > Width || y < 0 || y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gotoXY(x + i - 1, y + j - 1);
			std::cout << a[i][j];
		}
}

void Cell::remove() {
	if (x < 0 || x > Width || y < 0 || y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gotoXY(x + i - 1, y + j - 1);
			std::cout << " ";
		}
}

void Cell::move(direction direct) {
	remove();
	if (direct == 0) {
		if (y == 1) y = Height - 2;
		else y -= 3;
	}
	else if (direct == 1) {
		if (y == Height - 2) y = 1;
		else y += 3;
	}
	else if (direct == 2) {
		if (x == 1) x = Width;
		else x -= 3;
	}
	else if (direct == 3) {
		if (x == Width) x = 1;
		else x += 3;
	}
	else EXIT_ERROR("Wrong drirect: " + char(direct + '0'), 1);

	draw();
}