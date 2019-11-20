#ifndef SUPPORT_H
#define SUPPORT_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

const HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once

void EXIT_ERROR(std::string defineErr, int code);
void setColor(int k);
void fixConsoleScreen();
void gotoXY(int x, int y);

#endif