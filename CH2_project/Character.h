#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#include "Shop.h"

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
	static void destroyInstance();
	int getLevel();						// 몬스터 생성 시 사용하기 위해 추가
	int getHP();
	int getMaxHP();
	int setHP(int heal);
	int getAttack();
	int takeDamage(int damage);
	void setExp(int exp);
	vector<Item*>& getInventory();		// 아이템 판매 시 필요
	void addItem(Item* item);
	int getGold();
	void setGold(int gold);
	// 인벤토리에 있는 모든 아이템 메모리 해제
	~Character();
};