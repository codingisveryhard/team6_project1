#include "Utility.h"

//커서 이동하기
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// 키보드 커맨드
int keyControl() {
	char temp = _getch();

	if (temp == 'w') {
		return UP;
	}
	else if (temp == 'a') {
		return LEFT;
	}
	else if (temp == 's') {
		return DOWN;
	}
	else if (temp == 'd') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
	return 0;
}

// 커서 지우기
void eraseCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}


// 스페이스바 입력까지 기다리기
void wait() {
	while (1) {
		int n = keyControl();
		switch (n) {
		case SUBMIT:
			return;
		default:
			break;
		}
	}
}

void printScript(int& x, int& y, const string& text) {
	gotoxy(x, y++); // 현재 위치에 출력 후 Y 좌표 증가
	cout << text << endl;
}
