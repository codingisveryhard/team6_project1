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
// 원하는 아이템을 꺼내서 쓰는 기능 ai의 도움을 받아 구현
void Character::useItem(const string& itemName) {			// 아이템의 이름으로 인벤토리에서 검색
	auto it = std::find_if(inventory.begin(), inventory.end(),		// 솔직히 어떤 원리인지는 이해 못했습니다.
		[&](Item* item) {									// [&](Item* item) 무슨 의미일까요.
			if (!item) return false;
			return item->getName() == itemName;
		});

	if (it == inventory.end()) {
		cout << "소지하고 있지 않은 아이템입니다." << endl;
		return;
	}

	Item* item = *it; // 찾은 아이템
	item->use(this); // 아이템 사용
	cout << item->getName() << "을 사용했습니다" << endl;

	inventory.erase(it); // 인벤토리에서 제거
	delete item; // 메모리 해제
	cout << "남은 아이템 개수: " << inventory.size() << endl;
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
		choice = _getch() - '0';
		switch (choice) {
		case 1:
			cout << "어떤 아이템을 구매할텐가?" << endl;
			shop->displayItem();
			index = _getch() - '0';
			shop->buyItem(index - 1, this);
			break;
		case 2:
			cout << "어떤 아이템을 판매할텐가?" << endl;
			index = _getch() - '0';
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
	HP += heal;
	NotifyHP(HP, heal, true);
	return HP;
}

int Character::getAttack() {
	return attack;
}

int Character::setAttack(int buff)
{
	return attack += buff;
}

int Character::displayInventory()
{

	return 0;
}

int Character::takeDamage(int damage) {
	HP -= damage;
	if (HP - damage < 0) HP = 0;
	NotifyHP(HP, damage, false);

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
}

int Character::getGold() {
	return gold;
}

void Character::setGold(int gold) {

	this->gold += gold;
	cout << "현재 골드량: " << this->gold << endl;
}

Character::~Character() {
	for (Item* item : inventory) {
		delete item;  // 벡터에 저장된 모든 아이템 메모리 해제
	}
	inventory.clear();  // 벡터 초기화
}

void Character::Attach(const shared_ptr<IObserver>& observer) {
	observers.push_back(observer);
}

void Character::Detach(const shared_ptr<IObserver>& observer) {
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Character::NotifyHP(int HP, int change, bool isHeal) {
	for (const auto& observer : observers) {
		observer->updateHP(HP, change, isHeal);
	}
}
