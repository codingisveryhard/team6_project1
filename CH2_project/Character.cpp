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
		inventory.erase(inventory.begin() + 0);
		delete item;
		cout << "남은 아이템 개수: " << inventory.size() << endl;
	}
}

void Character::visitShop() {
	cout << "상점을 방문했습니다." << endl;
	bool exitShop = false;
	Shop* shop = new Shop;
	while (!exitShop){
		cout << "1. 아이템 구매" << endl;
		cout << "2. 아이템 판매" << endl;
		cout << "3. 상점 나가기" << endl;


		int choice;
		int index;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "어떤 아이템을 구매할텐가?" << endl;
			shop->displayItem();
			cin >> index;
			cin.ignore();
			shop->buyItem(index - 1, this);
			break;
		case 2:
			cout << "어떤 아이템을 판매할텐가?" << endl;
			cin >> index;
			cin.ignore();
			shop->sellItem(index - 1, this);
			break;
		case 3:
			exitShop = true;
			delete shop;
			break;
		}


	}
}

void Character::destroyInstance(){
	delete instance;  // 메모리 해제
	instance = nullptr;  // 안전하게 포인터 초기화
	cout << "Character 인스턴스를 삭제합니다." << endl;
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

vector<Item*>& Character::getInventory()
{
	return inventory;
}

void Character::addItem(Item* item) {
	if (item != nullptr) {
		inventory.push_back(item);
		cout << "아이템: " << item->getName() << "을 인벤토리에 넣었습니다." << endl;
	}
	cout << "아이템 추가됨: " << item->getName() << ", 현재 아이템 개수: " << inventory.size() << endl;
}

int Character::getGold() {
	return gold;
}

void Character::setGold(int gold) {
	if (gold >= 0) cout << "골드를 " << gold << "만큼 획득하셨습니다." << endl;
	else cout << "골드를 " << gold * -1 << "만큼 소모하셨습니다." << endl;
	this->gold += gold;
	cout << "현재 골드량: " << this->gold << endl;
}

Character::~Character() {
	for (Item* item : inventory) {
		delete item;  // 벡터에 저장된 모든 아이템 메모리 해제
	}
	inventory.clear();  // 벡터 초기화
}
