#include "Background.h"

void title()
{

	cout << endl << endl << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl <<
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠊⠑⠀⠀⡃⡹⡄⠸⡄⠀⢴⠁⡴⡑⡑⣆⠀⠀⠀⠀⣰⠑⠙⠴⡀⠙⡏⠁⠀⠀⠀⢜⠎⠊⡶⠊⠱⣂⠠⡇⢀⢾⠈⠓⡄⢀⡖⠙⠘⡮⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl <<
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⡁⠀⡀⢼⠊⢉⡧⠀⢳⡨⠆⠀⢯⠁⠉⡁⠀⠀⠀⠀⢧⡀⠀⣸⠁⠨⡇⠀⠀⠀⠀⡹⠄⠀⡽⠀⠀⡇⢐⢇⠀⡧⠀⠐⡇⠸⣂⠀⢀⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl <<
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠈⠉⠁⠁⠀⠀⠉⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠈⠁⠀⠀⠀⠀⠈⠁⠀⠉⠀⠀⠁⠀⠁⠀⠁⠀⠀⠁⠀⠈⠉⠁⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;


}

void gameInfo()
{
	cout << endl << endl << endl << "				여백의 미";
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
	while (1) {
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
