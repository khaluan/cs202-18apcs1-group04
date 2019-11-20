#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <mutex>
#include <stdlib.h>
#include <time.h>

#define GREEN 10
#define BLUE 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

static std::mutex m;
const HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once

void EXIT_ERROR(std::string defineErr, int code);
void setColor(int k);
void fixConsoleScreen();
void gotoXY(int x, int y);
int random(int l, int r);
void ShowConsoleCursor(bool showFlag);

#endif