#pragma once
#include "Character.h"
#include "Monster.h"
#include "Utility.h"
#include "Script.h"
#include "Background.h"


class GameManager {
private:
	int stageNum = 1;
public:
	Monster* generateMonster(int level);
	void battle(Character* player);
	void visitShop(Character* player);
	void displayInventory(Character* player);
	void stageDraw(int stagenum);
	void monsterDraw(int stagenum);
};