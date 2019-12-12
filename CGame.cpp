#include "CGame.h"
#include <thread>
#include "Level.h"

std::string CGame::Null = "";

CGame::CGame() {

}

levelState CGame::playLevel(std::string & dir)
{
	Level gameLevel;
	if (dir == "") { //If there is no loadDirectory => Init level
		gameLevel = Level(curLevel);
	}
	else {
		gameLevel.loadGame(dir);
		curLevel = gameLevel.getLevel();
		dir = "";
	}
	while (true) {
		gameLevel.drawGame();
		levelState state = gameLevel.process();
		switch (state)
		{
		case WIN:
			return WIN;
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
		case SAVEGAME: {
			std::string dir = scr.saveMenu();
			gameLevel.saveGame(dir);
			break;
		}
		case LOAD: 
			return LOAD;
		case EXIT:
			return EXIT;
		case LOSE: 
			return LOSE;
		default:
			break;
		}
	}
}


CGame::~CGame() {

}

void CGame::Run()
{
	while (true) {
		mainChoice choice = scr.mainMenu();
		switch (choice)
		{
		case NEWGAME:
			Play();
			break;
		case LOADGAME: {
			std::string saveGameName = scr.loadMenu();
			Play(saveGameName);
		}
		case SETTING:
			break;
		default:
			return;
		}
	}
}

void CGame::Play(std::string dir)
{
	while (curLevel < maxLevel) {
		levelState state = playLevel(dir);
		switch (state)
		{
		case WIN:
			++curLevel;
			break;
		case LOSE: {
			pauseChoice choice = scr.loseMenu();
			switch (choice)
			{
				case YES:
					break;
				case NO:
					curLevel = 1;
					return;
				default:
					break;
			}
			break;
		}
		case LOAD: {
			std::string dir = scr.loadMenu();
			playLevel(dir);
			break;
		}
		case EXIT:
			return;
		default:
			break;
		}
	}
	//TODO: Win screen
}

//void CGame::playLoadGame(std::string & loadFilename)
//{
//	Level gameLevel;
//	gameLevel.loadGame(loadFilename);
//
//	while (curLevel < maxLevel) {
//		levelState state = playLevel(gameLevel);
//		switch (state)
//		{
//		case WIN:
//			++curLevel;
//			gameLevel = Level(curLevel);
//			break;
//		case LOSE: {
//			pauseChoice choice = scr.pauseMenu();
//			switch (choice)
//			{
//			case YES:
//				break;
//			case NO:
//				gameLevel.~Level();
//				Run();
//				return;
//			default:
//				break;
//			}
//			break;
//		}
//		case PAUSE: {
//			pauseChoice choice = scr.pauseMenu();
//			switch (choice)
//			{
//			case YES:
//				break;
//			case NO:
//				Run();
//				return;
//			default:
//				break;
//			}
//		}
//		case EXIT:
//			Run();
//			return;
//			break;
//		default:
//			break;
//		}
//	}
//}

//void Level::resetScreen()
//{
//	for (int i = 0; i < Height; ++i)
//		for (int j = 0; j < Width; ++j)
//			screen[i][j] = 0;
//}
