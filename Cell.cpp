#include "Cell.h"
#include "Support.h"
#include "Screen.h"
#include <iostream>


Cell::Cell(int x, int y) {
	init(x,y);
}

void Cell::init(int x, int y) {
	_x = x; _y = y;
	w = 3, h = 3;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			a[i][j] = (char)255;
			subShape[i][j] = (char)255;
		}
	a[0][0] = (char)223;
	a[1][0] = (char)220;
	a[2][0] = (char)223;
}

void Cell::draw() {
	if (_x < 0 || _x > Width || _y < 0 || _y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gotoXY(_x + i - 1, _y + j - 1);
			std::cout << a[i][j];
		}
}

void Cell::subDraw() {
	if (_x < 0 || _x > Width || _y < 0 || _y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gotoXY(_x + i - 1, _y + j - 1);
			std::cout << subShape[i][j];
		}
}

void Cell::remove() {
	if (_x < 0 || _x > Width || _y < 0 || _y > Height) return;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gotoXY(_x + i - 1, _y + j - 1);
			std::cout << " ";
		}
}

void Cell::input(std::ifstream& fin) {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			fin >> a[i][j];
}

void Cell::inputSub(std::ifstream& fin) {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			fin >> subShape[i][j];
}

void Cell::move(int direct) {
	remove();
	if (direct == 0) {
		if (_y == 1) _y = Height - 2;
		else _y -= 3;
	}
	else if (direct == 1) {
		if (_y == Height - 2) _y = 1;
		else _y += 3;
	}
	else if (direct == 2) {
		if (_x == 1) _x = Width;
		else _x -= 3;
	}
	else if (direct == 3) {
		if (_x == Width) _x = 1;
		else _x += 3;
	}
	else EXIT_ERROR("Wrong drirect: " + char(direct + '0'), 1);

	draw();
}