#include "Character.h"

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string name) {
	this->name = name;
	maxHP = 200;
	maxMP = 20;
	attack = 30;
	level = 1;
	exp = 0;
	gold = 0;
	HP = maxHP;
	MP = maxMP;

}

Character* Character::getInstance(string name) {
	if (instance == nullptr) {
		instance = new Character(name);
	}
	return instance;
}

void Character::displayStatus() {
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << HP << "/" << maxHP << endl;
	cout << "MP: " << MP << endl;
	cout << "Attack: " << attack << endl;
	cout << "Exp: " << exp << endl;
}

void Character::levelUp() {
	while (exp >= 100) {
		level++;
		exp %= 100;
		cout << "레벨업! 현재 레벨: " << level << endl;
		maxHP = maxHP + 20;
		maxMP = maxMP + 10;
		attack = attack + 5;
		HP = maxHP;
	}
}
// 원하는 아이템을 꺼내서 쓰는 기능 구현 못함
void Character::useItem(int index) {
	if (index < 0 || index >= inventory.size()) {
		cout << "소지하고 있지 않은 아이템입니다." << endl;
		return;
	}

	else {
		Item* item = inventory[0];
		item->use(this);
		cout << item->getName() << "을 사용했습니다" << endl;
	}
}

void Character::visitShop() {
}

int Character::getLevel() {
	return level;
}

int Character::getHP() {
	return HP;
}

int Character::getMaxHP()
{
	return maxHP;
}

int Character::setHP(int heal) {
	return HP += heal;
}

int Character::getAttack() {
	return attack;
}

int Character::takeDamage(int damage) {
	if (HP - damage < 0) HP = 0;
	else HP -= damage;
	return HP;
}

void Character::setExp(int exp) {
	this->exp += exp;
	cout << exp << " 경험치 획득!" << endl;
	levelUp(); // 레벨업 확인
}

void Character::addItem(Item* item) {
	inventory.push_back(item);
	cout << "아이템: " << item->getName() << "을 인벤토리에 넣었습니다." << endl;
}
