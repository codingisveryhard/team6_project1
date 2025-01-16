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

void Script::playerStartScript(string monstername)
{
	int x = 7;
	int y = 19;
	printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀      ⠀           ⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀    ⠀    ⠀⠀       ⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
	x = 9;
	y = 20;
	if (monstername == "눈을 가린 괴물") {
		printScript(x, y, "이게... 무슨 일이지? 너는..?");
		printScript(x, y, "못알아듣는건가..? 뭐..뭐야...으아악!!");
	}
	else if (monstername == "백개의 눈") {
		printScript(x, y, "어디서 이런소리가 들리는거지?");
		printScript(x, y, "이 소리들은..");
	}
	else if (monstername == "귀 큰 괴물") {
		printScript(x, y, "...............");
		printScript(x, y, "조용히 접근해야겠어");
	}
	else if (monstername == "구멍 뚫린 괴물") {
		printScript(x, y, "으악! 몸에 구멍이 나있어??!!!");
		printScript(x, y, "이 녀석은 또 어떻게 해치워야 하는걸까..");

	}
	else if (monstername == "낯익은 어린아이") {
		printScript(x, y, "그건 다 옛날 얘기일뿐이야..");
	}
	else if (monstername == "친숙한 괴물") {
		printScript(x, y, "....당신은");
		printScript(x, y, "일단 전투에 집중하자");
	}
	else if (monstername == "얼굴없는 남자") {
		printScript(x, y, "“그것”으로 인해 많은것을 겪었죠");
		printScript(x, y, "겨우 여기까지 도달할 수 있었습니다.");
		wait();
		x = 9;
		y = 20;
		printScript(x, y, "이번이 마지막이 되기를            ");
		printScript(x, y, "당신은 의지로 가득찼다.            ");
	}
}

void Script::playerWinScript(string monstername)
{
	int x = 7;
	int y = 19;
	printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀      ⠀           ⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀    ⠀    ⠀⠀       ⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
	x = 9;
	y = 20;
	// 주인공 대사 0116
	if (monstername == "BlindMonster") {
		printScript(x, y, "갑자기 공격하다니 위험했어");
		printScript(x, y, "빨리 이곳을 나가자");
	}
	else if (monstername == "EyesMonster") {
		printScript(x, y, "어째서 괴물들을 만나게 된거지...?");
		printScript(x, y, "앞으로 이런 것들이 얼마나 더 있는걸까");
	}
	else if (monstername == "BigEaredMonster") {
		printScript(x, y, "이것들은...도대체");
	}
	else if (monstername == "PerforatedMonster") {
		printScript(x, y, "더 나아가보자");
	}
	else if (monstername == "ChildMonster") {
		printScript(x, y, "모든것이 끝나가고 있다.");
	}
	else if (monstername == "CryingMonster") {
		printScript(x, y, "당신은 여정의 끝이 보이는 듯 하다.");
	}
	else if (monstername == "FacelessMan") {
		printScript(x, y, "모든것이 끝나고 당신은 문앞에 서게된다 ");
	}
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
