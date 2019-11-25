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

void Cell::init(int x, int y) {
	this->x = x;
	this->y = y;
}

void Cell::input(std::ifstream & fin)
{
	//TODO: 
}

void Cell::draw(bool isLight) {
	if ((x < 0 || x > Width || y < 0 || y > Height) && !isLight) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			m.lock();
			gotoXY(x + j - 1, y + i - 1);
			std::cout << a[j][i];
			m.unlock();
		}
}

void Cell::remove() {
	if (x < 0 || x > Width || y < 0 || y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = -1; j < w; ++j) {
			m.lock();
			gotoXY(x + j - 1, y + i - 1);
			std::cout << (char)255;
			m.unlock();
		}
}

void Cell::move(direction direct, int stepX, int stepY) {
	remove();
	if (direct == 0) {
		if (y - stepY >= 1)
			y -= stepY;
	}
	else if (direct == 1) {
		if (y + stepY <= Height)
			y += stepY;
	}
	else if (direct == 2) {
		if (x <= 1) x = Width;
		else x -= stepX;
	}
	else if (direct == 3) {
		if (x >= Width) x = 1;
		else x += stepX;
	}
	else EXIT_ERROR("Wrong drirect: " + char(direct + '0'), 1);

	draw();
}

void Cell::changeColor(bool color) {
	m.lock();
	gotoXY(x , y - 1);
	if (color) setColor(RED);
	else setColor(GREEN);
	std::cout << a[1][1];
	setColor(WHITE);
	m.unlock();
}

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}
