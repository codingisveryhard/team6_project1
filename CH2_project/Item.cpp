#include "Item.h"

string Item::getName()
{
	return string();
}

void Item::use(Character* character)
{
}

HealthPotion::HealthPotion()
{
	name = "HealthPotion";
	healthRestore = 50;
}

string HealthPotion::getName()
{
	return name;
}

// 체력회복을 정해진 값이 아닌 최대체력 비례로 만들어 보았다.
void HealthPotion::use(Character* character)
{
	int beginHP = character->getHP();
	int maxHP = character->getMaxHP();
	healthRestore = maxHP * 0.3;
	character->setHP(healthRestore);
	cout << "체력이 " << beginHP << " -> " << character->getHP() << "(" << healthRestore << ")" << " 만큼 회복되었습니다." << endl;
}

AttackBoost::AttackBoost()
{
	name = "HealthPotion";
	attackBoost = 10;
}

string AttackBoost::getName()
{
	return string();
}

void AttackBoost::use(Character* character)
{
}
