#pragma once
#include <iostream>
#include "Utility.h"


using namespace std;

class Script {
private:
	int X = 20;
	int Y = 10;

public:
	void start();
	void LocateXY(int x, int y);
};
