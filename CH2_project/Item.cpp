#include "Item.h"

string Item::getName() const
{
	return name;
}

void Item::use(Character* character)  {
}

int Item::getPrice() const
{
	return price;
}

Item* MorPhinePotion::clone() const {
	return new MorPhinePotion(*this); // 복사본 반환
}

void MorPhinePotion::use(Character* character) {
	character->setAttack(attackPower); // 체력회복
}

Item* CocainePotion::clone() const {
	return new CocainePotion(*this); // 복사본 반환
}

void CocainePotion::use(Character* character) {
	character->setAttack(attackPower); //공격력 증가
}

Item* HeroinPotion::clone() const {
	return new HeroinPotion(*this); // 복사본 반환
}

void HeroinPotion::use(Character* character) {
	character->setMaxHP(healthRestore); //체력 회복
}

Item* LSDPotion::clone() const {
	return new LSDPotion(*this); // 복사본 반환
}

void LSDPotion::use(Character* character) {
	character->setMaxHP(healthRestore); //체력회복
	character->setAttack(attackPower); //공격력 증가
}

Item* IVbeltWeapon::clone() const {
	return new IVbeltWeapon(*this); // 복사본 반환
}

void IVbeltWeapon::use(Character* character) {
	character->setAttack(attackPower); //공격력 증가
}
