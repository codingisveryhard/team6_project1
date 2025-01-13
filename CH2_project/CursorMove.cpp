#include "CursorMove.h"
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define SUBMIT 4

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


// 커서 위치 이동
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void eraseCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}



// 타이틀 메뉴창
int menuDraw()
{
	int x = 46;
	int y = 12;
	gotoxy(x - 2, y);
	cout << "> 게임시작";
	gotoxy(x, y + 1);
	cout << "게임정보";
	gotoxy(x, y + 2);
	cout << "  종료  ";
	gotoxy(x - 26, y + 12);
	cout << "w, s 를 눌러 위, 아래로 움직이고 스페이스 바를 눌러 선택해주세요.";
	gotoxy(x - 1, y);
	while(1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 12) {
				gotoxy(x - 2, y);
				cout << " ";
				y--;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 14) {
				gotoxy(x - 2, y);
				cout << " ";
				y++;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		case SUBMIT:
			return y - 12;
		default:
			break;
		}
	}

	return 0;
}


