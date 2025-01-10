#pragma once
#include <string>
#include "Character.h"

using namespace std;

class Character;

class Item {
public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
	virtual ~Item() {
	
	}
	virtual int getPrice() = 0;
};


class HealthPotion : public Item {
private:
	string name;
	int healthRestore = 50;
	int price = 30;

public:
	HealthPotion();
	string getName();
	int getPrice();
	void use(Character* character);
};

class AttackBoost : public Item {
private:
	string name;
	int attackBoost = 10;
	int price = 30;

public:
	AttackBoost();
	string getName();
	int getPrice();
	void use(Character* character);
};