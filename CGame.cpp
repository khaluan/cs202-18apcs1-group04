#include "CGame.h"
#include <thread>
#include "Level.h"

std::string CGame::Null = "";

CGame::CGame() {
	ConfigData::load();
}

levelState CGame::playLevel(std::string & dir){
	initScreen(12);
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
			initScreen(24);
			pauseChoice choice = scr.pauseMenu();
			if (choice == NO) {
				Road::CHANGE_EXIT();
				return EXIT;
			}
			else {
				initScreen(12);
				Road::CHANGE_PAUSE();
			}
				break;
		}
		case SAVEGAME: {
			initScreen(24);
			std::string dir = scr.saveMenu();
			gameLevel.saveGame(dir);
			if (dir != "") scr.saveScreen();
			initScreen(12);
			break;
		}
		case LOAD: 
			system("cls");
			return LOAD;
		case EXIT:
			system("cls");
			return EXIT;
		case LOSE: 
			system("cls");
			return LOSE;
		default:
			break;
		}
	}
}


CGame::~CGame() {
	ConfigData::save();
}

void CGame::Run()
{
	if (ConfigData::soundOn)
		PlaySound(TEXT("Data/GamesSong.wav"), NULL, SND_ASYNC | SND_LOOP);
	initScreen(24);
	scr.splashScreen();
	while (true) {
		initScreen(24);
		mainChoice choice = scr.mainMenu();
		switch (choice)
		{
		case NEWGAME:
			curLevel = 1;
			initScreen(12);
			Play();
			system("cls");
			break;
		case LOADGAME: {
			//initScreen(24);
			std::string saveGameName = scr.loadMenu();
			system("cls");
			initScreen(12);
			if (saveGameName == "") break;
			Play(saveGameName);
			break;
		}
		case SETTING:
			scr.settingMenu();
			break;
		default:
			return;
		}
	}
}

void CGame::Play(std::string dir)
{
	levelState state = DEFAULT;
	while (curLevel <= maxLevel) {
		if (state == LOAD) {
			initScreen(24);
			std::string dir = scr.loadMenu();
			system("cls");
			initScreen(12);
			state = playLevel(dir);
		}
		else {
			switch (state)
			{
			case WIN:
				++curLevel;
				if (curLevel == 11) {
					initScreen(24);
					scr.winScreen();
					initScreen(12);
					curLevel = 1;
					return;
				}	
				break;
			case LOSE: {
				/*TODO: LOSE EFFECT HERE*/
				initScreen(24);
				scr.loseScreen();
				pauseChoice choice = scr.loseMenu();
				switch (choice)
				{
					case YES:
						initScreen(12);
						system("cls");
						break;
					case NO:
						curLevel = 1;
						return;
					default:
						break;
				}
				break;
			}
			case LOAD:
				continue;
			case EXIT:
				return;
			default:
				break;
			}
			state = playLevel(dir);
		}
	}
}
