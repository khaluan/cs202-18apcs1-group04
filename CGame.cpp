#include "CGame.h"
#include <thread>
#include "Level.h"

CGame::CGame() {

}

levelState CGame::playLevel(Level& gameLevel)
{
	while (true) {
		levelState state = gameLevel.process();
		switch (state)
		{
		case WIN:
			return WIN;
			break;
		case PAUSEGAME: {
			pauseChoice choice = scr.pauseMenu();
			if (choice == NO) {
				Road::CHANGE_EXIT();
				return EXIT;
			}
			else
				Road::CHANGE_PAUSE();
			break;
		}
		case EXIT:
			return EXIT;
			break;
		case LOSE: {
			pauseChoice choice = scr.pauseMenu();
			if (choice == NO)
				return EXIT;
			else
				return LOSE;
			break;
		}
		default:
			break;
		}
	}
}


CGame::~CGame() {

}

void CGame::Run()
{
	mainChoice choice = scr.mainMenu();
	switch (choice)
	{
	case NEWGAME:
		Play();
		break;
	case LOADGAME: {
		std::string saveGameName = scr.loadMenu();
		playLoadGame(saveGameName);
	}
	case SETTING:
		break;
	default:
		break;
	}
	return;
}

void CGame::Play()
{
	while (curLevel < maxLevel) {
		Level gameLevel(curLevel);
		levelState state = playLevel(gameLevel);
		switch (state)
		{
		case WIN:
			++curLevel;
			break;
		case LOSE: {
			pauseChoice choice = scr.pauseMenu();
			switch (choice)
			{
			case YES:
				break;
			case NO:
				Run();
				return;
			default:
				break;
			}
			break;
		}
		case SAVEGAME:
			break;
		case LOAD:
			break;
		case PAUSEGAME: {
			pauseChoice choice = scr.pauseMenu();
			switch (choice)
			{
			case YES:
				break;
			case NO:
				Run();
				return;
			default:
				break;
			}
		}
		case EXIT:
			Run();
			return;
			break;
		default:
			break;
		}
	}
	//TODO: Win screen
}

void CGame::playLoadGame(std::string & loadFilename)
{
	Level gameLevel;
	gameLevel.loadGame(loadFilename);

	while (curLevel < maxLevel) {
		levelState state = playLevel(gameLevel);
		switch (state)
		{
		case WIN:
			++curLevel;
			gameLevel = Level(curLevel);
			break;
		case LOSE: {
			pauseChoice choice = scr.pauseMenu();
			switch (choice)
			{
			case YES:
				break;
			case NO:
				Run();
				return;
			default:
				break;
			}
			break;
		}
		case PAUSE: {
			pauseChoice choice = scr.pauseMenu();
			switch (choice)
			{
			case YES:
				break;
			case NO:
				Run();
				return;
			default:
				break;
			}
		}
		case EXIT:
			Run();
			return;
			break;
		default:
			break;
		}
	}
}

//void Level::resetScreen()
//{
//	for (int i = 0; i < Height; ++i)
//		for (int j = 0; j < Width; ++j)
//			screen[i][j] = 0;
//}
