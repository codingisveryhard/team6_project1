#include "Script.h"


void Script::start() {
	LocateXY(20, 10);
	printScript(X, Y, "으윽..머리가 아파..");
	printScript(X, Y, "어? 여긴 어디인거지?");
	printScript(X, Y, "너무 무섭고 어두워서 잘 안보여...");
	printScript(X, Y, "어..?");
	printScript(X, Y, "여기..지금 병원인건가..?");				// 대놓고 병원?
	printScript(X, Y, "어..뭐지..");
	printScript(X, Y, "너무 무섭고 어두워서 잘 안보여...");
	printScript(X, Y, "여기 무언가 이상해..");
	printScript(X, Y, "안되겠다 여길 빠져 나와야겠어.");

}

void Script::LocateXY(int x, int y) {
	X = x;
	Y = y;
}
