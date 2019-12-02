#ifndef CBIRD_H
#define CBIRD_H
#include "Obstacle.h"
class CBird :
	public Obstacle
{
public:
	CBird(int x, int y, std::vector<std::vector<std::vector<char>>> shape);
	void tell();
	~CBird();
private:

};

#endif

