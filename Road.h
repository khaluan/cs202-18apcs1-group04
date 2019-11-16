#pragma once
#include "Support.h"
class Road
{
public:
	Road();
	Road(int a, int b);
	virtual void display(const int & width, const int & height);// display the lane
	virtual ~Road();
private:
	int upper, lower;//y coordinate of upper and lower boundary
};

