#include "Cell.h"
#include "Support.h"
#include "Screen.h"
#include "Level.h"
#include <iostream>

Cell::Cell(int x, int y, std::vector<std::vector<std::vector<char>>> shape) {
	this->x = x; this->y = y;
	this->a = shape;
	this->h = shape[0].size();
	this->w = shape[0][0].size();
	idPic = 0;
}

bool Cell::draw(bool isLight) {
	bool res = 0;
	if ((x < 0 || x > Width || y < 0 || y > Height) && !isLight) return 0;


	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) if (a[idPic][i][j] != char(255)) {
			int u = x + j - w / 2, v = y + i - h / 2;
			if ((u <= 0 || u >= Width) && !isLight) continue;

			m.lock();
			if (u >= 0 && u < Width && v >= 0 && v < Height && !Level::isPixelNull(v, u)) res = 1;
			if (!isLight && u >= 0 && u < Width && v >= 0 && v < Height) Level::setScreen(v, u, true);
			gotoXY(u, v);
			std::cout << a[idPic][i][j];
			m.unlock();
		}


	return res;
}

void Cell::remove() {
	if (x < 0 || x > Width || y < 0 || y > Height) return;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) if (a[idPic][i][j] != char(255)){
			int u = x + j - w/2, v = y + i - h/2;
			if (u < 0 || u >= Width || v < 0  || v >= Height) continue;
			
			m.lock();
			Level::setScreen(v, u, false);
			gotoXY(u, v);
			std::cout << (char)255;
			m.unlock();
		}

	++idPic;
	idPic %= a.size();
}

bool Cell::move(direction direct, int stepX, int stepY) {
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
		//else --x;
		else x -= stepX;
	}
	else if (direct == 3) {
		if (x >= Width) x = 1;
		//else ++x;
		else x += stepX;
	}
	else EXIT_ERROR("Wrong drirect: " + char(direct + '0'), 1);

	return draw();
}

void Cell::changeColor(bool color) {
	m.lock();
	if (color) setColor(RED);
	else setColor(GREEN);

	gotoXY(x, y);
	std::cout << a[0][1][1];

	gotoXY(x, y - 1);
	std::cout << a[0][1][1];

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

void Cell::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Cell::operator==(const Cell& a) {
	return x == a.x && y == a.y;
}

void Cell::save(std::ofstream & fileGame)
{
	//fileGame << x << " " << y << std::endl;
	fileGame.write((char*)&x, sizeof(x));
	fileGame.write((char*)&y, sizeof(y));
}

void Cell::load(std::ifstream & fileGame)
{
	//fileGame >> x >> y;
	fileGame.read((char*)&x, sizeof(x));
	fileGame.read((char*)&y, sizeof(y));
}
