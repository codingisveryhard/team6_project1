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
	LocateXY(28, 30);
	printScript(X, Y, "※스페이스 바를 눌러 계속해서 진행해주세요.※");
	
	wait();
	system("cls");
}

void Script::LocateXY(int x, int y) {
	X = x;
	Y = y;
}

void Script::printbattleLog(const string& text) {
	gotoxy(battleX, battleY);
	battleLogQue.push(text);
	if (battleLogQue.size() > 6) {
		battleLogQue.pop();
	}
	int currentY = battleY; // 초기 Y 좌표 저장
	queue<string> tempQueue = battleLogQue; // 원본 큐를 임시 큐로 복사

	// 큐에서 로그를 하나씩 꺼내서 출력
	while (!tempQueue.empty()) {
		gotoxy(battleX, currentY); // Y 좌표로 커서 이동
		cout << string(50, ' '); // 해당 위치를 빈 공간으로 덮어쓰기 (기존 내용 지우기)
		gotoxy(battleX, currentY++); // Y 좌표를 줄여가며 출력
		cout << tempQueue.front();   // 로그 출력
		tempQueue.pop(); // 출력한 로그 제거
	}
}


