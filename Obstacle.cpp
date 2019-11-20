#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(int x, int y, std::vector<std::vector<char>> shape)
{
	this->shape = Cell(x, y, shape);
}

void Obstacle::move(direction direct)
{
	shape.move(direct);
}

void Obstacle::display(bool isLight)
{
	shape.draw(isLight);
}

void Obstacle::remove()
{
	shape.remove();
}

void Obstacle::changeColor(bool Color) {
	shape.changeColor(Color);
}

void Obstacle::tell()
{
}

Obstacle::~Obstacle()
{
}
