#pragma once
#include "Item.h"
#include <string>
using namespace std; // 수정사항 250115

class Monster {
public:
	virtual string getName() = 0;
	virtual int getHP() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;
	virtual Item* dropItem() = 0;

	virtual void speak() = 0; // 수정사항 250115
	virtual ~Monster() {
	}
};

class Goblin : public Monster {
private:
	string name;
	int health;
	int attack;
	MorPhinePotion morphinePotion; // 드랍할 원본 아이템

public:
	Goblin(int level);
	string getName() override;
	int getHP() override;
	int getAttack() override;
	void takeDamage(int damage) override;
	Item* dropItem() override;

	void speak() override; //수정사항 250115
};

class Orc : public Monster {
private:
	string name;
	int health;
	int attack;
	MorPhinePotion morphinePotion; // 드랍할 원본 아이템

public:
	Orc(int level);
	string getName() override;
	int getHP() override;
	int getAttack() override;
	void takeDamage(int damage) override;
	Item* dropItem() override;
	
	void speak() override; // 수정사항 250115
};

class Troll : public Monster {
private:
	string name;
	int health;
	int attack;
	MorPhinePotion morphinePotion; // 드랍할 원본 아이템

public:
	Troll(int level);
	string getName() override;
	int getHP() override;
	int getAttack() override;
	void takeDamage(int damage) override;
	Item* dropItem() override;

	void speak() override; //수정사항 250115
};

class BossMonster : public Monster {
private:
	string name;
	int health;
	int attack;

public:
	BossMonster(int level);
	string getName() override;
	int getHP() override;
	int getAttack() override;
	void takeDamage(int damage) override;
	Item* dropItem() override;

	void speak() override; //수정사항 250115
};
