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

void Obstacle::display()
{
	shape.draw();
}

void Obstacle::remove()
{
	shape.remove();
}

void Obstacle::tell()
{
}

Obstacle::~Obstacle()
{
}
