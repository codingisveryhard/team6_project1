#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define SUBMIT 4
// 초기에는 클래스로 만들려했으나 이곳저곳에 계속 사용되어서 그냥 함수로 빼두었습니다.

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};


using namespace std;


// 커서 위치 이동
void gotoxy(int x, int y);

int keyControl();

void eraseCursor();

void wait();

void printScript(int& x, int& y, const string& text);

void setColor(int, int);

