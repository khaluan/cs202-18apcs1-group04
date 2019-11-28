#ifndef SCREEN_H
#define SCREEN_H

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

	static bool* constructor();
	static void setScreen(int i, int j, int c);
	static bool isPixelNull(int i, int j);
private:
	const int height = 30, width = 100; //Fix later
	static bool* screen;
};

#endif // !SCREEN_H
