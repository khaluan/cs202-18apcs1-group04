#include "CGame.h"
#include "CPeople.h"

int main() {
	srand(time(NULL));
	ShowConsoleCursor(false);
	
	CGame a;
	a.process();

	return 0;
}