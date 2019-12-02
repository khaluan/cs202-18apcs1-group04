#ifndef CAR_H
#define CAR_H

#include "Obstacle.h"
class CCar :
	public Obstacle
{
public:
	CCar(int x, int y, std::vector<std::vector<std::vector<char>>> shape);
	~CCar();
};

#endif // !CAR_H
