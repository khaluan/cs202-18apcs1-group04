#ifndef SUPPORT_H
#define SUPPORT_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <mutex>
#include <stdlib.h>
#include <time.h>
#include <mutex>
#include <fstream>
#include <vector>

#define GREEN 10
#define BLUE 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

static std::mutex m;
const HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once

void initScreen(const int& ySize);
void fixScreen();
void EXIT_ERROR(std::string defineErr, int code);
void setColor(int k);
void fixConsoleScreen();
void gotoXY(int x, int y);
int random(int l, int r);
void ShowConsoleCursor(bool showFlag);
std::vector<std::string> read_directory(const std::string& directory);
void instruction();

#endif