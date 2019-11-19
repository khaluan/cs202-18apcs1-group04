#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <mutex>

static std::mutex m;
const HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once

void EXIT_ERROR(std::string defineErr, int code);
void setColor(int k);
void fixConsoleScreen();
void gotoXY(int x, int y);

#endif