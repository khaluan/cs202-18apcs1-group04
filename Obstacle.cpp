#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(int x, int y, std::vector<std::vector<std::vector<char>>> shape)
{
	this->shape = Cell(x, y, shape);
}

bool Obstacle::move(direction direct)
{
	return shape.move(direct);
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

void Obstacle::save(std::ofstream & fileGame)
{
	shape.save(fileGame);
}

void Obstacle::load(std::ifstream & fileGame)
{
	shape.load(fileGame);
}

void Obstacle::tell()
{
}

Obstacle::~Obstacle()
{
}
