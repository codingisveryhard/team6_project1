#pragma once
#include "Character.h"
#include "Monster.h"
#include "Utility.h"


class GameManager {
public:
	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	void battle(Character* player);
	void visitShop(Character* player);
	void displayInventory(Character* player);
};