#pragma once
#include <iostream>
#include "Utility.h"
#include <queue>


using namespace std;

class Script {
private:
	int X = 20;
	int Y = 10;
	int battleX = 15;
	int battleY = 25;
	queue<string> battleLogQue;

public:
	void start();
	void playerStartScript(string monstername);
	void playerWinScript(string monstername);

	void LocateXY(int x, int y);

	void printbattleLog(const string& text);

};
