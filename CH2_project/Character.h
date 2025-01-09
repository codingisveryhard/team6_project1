#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Item;

class Character {
private:
	static Character* instance;;
	int maxHP;
	int HP;
	int maxMP;
	int MP;
	string name;
	int level;
	int attack;
	int exp;
	int gold;
	vector<Item*> inventory;
	Character(string name);

public:
	static Character* getInstance(string name);
	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();

	//추가된 메서드
	int getLevel();						// 몬스터 생성 시 사용하기 위해 추가
	int getHP();
	int getMaxHP();
	int setHP(int heal);
	int getAttack();
	int takeDamage(int damage);
	void setExp(int exp);
	void addItem(Item* item);
};