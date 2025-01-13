#include "Item.h"

string Item::getName() const
{
	return name;
}

void Item::use(Character* character) {
}

void MorPhinePotion::use(Character* character) {
	character->setHP(healthRestore); // 체력회복
}

int MorPhinePotion::getPrice()
{
	return price;
}

void CocainePotion::use(Character* character) {
	character->setAttack(attackPower); //공격력 증가
}

int CocainePotion::getPrice()
{
	return price;
}

void HeroinPotion::use(Character* character) {
	character->setHP(healthRestore); //체력 회복
}

int HeroinPotion::getPrice()
{
	return price;
}

void LSDPotion::use(Character* character) {
	character->setHP(healthRestore); //체력회복
	character->setAttack(attackPower); //공격력 증가
}

int LSDPotion::getPrice()
{
	return price;
}

void IVbeltWeapon::use(Character* character) {
	character->setAttack(attackPower); //공격력 증가
}

int IVbeltWeapon::getPrice()
{
	return price;
}
