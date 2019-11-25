#pragma once
#include "Support.h"

const int Height = 30;
const int Width = 100;



class Screen
{
public:
	Screen();
	~Screen();
	int stateMove(int& state, int n);
	int pauseMenu();
private:
	const int height = 30, width = 100; //Fix later
};