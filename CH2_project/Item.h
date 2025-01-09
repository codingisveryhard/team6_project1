#pragma once
#include <string>
#include "Character.h"

using namespace std;

class Character;

class Item {
public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
};


class HealthPotion : public Item {
private:
	string name;
	int healthRestore = 50;

public:
	HealthPotion();
	string getName();
	void use(Character* character);
};

class AttackBoost : public Item {
private:
	string name;
	int attackBoost = 10;

public:
	AttackBoost();
	string getName();
	void use(Character* character);
};