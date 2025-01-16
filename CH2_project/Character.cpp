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
	int x = 21;
	int y = 14;
	printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⣿");
	printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿");
	printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
	x = 23;
	y = 16;
	printScript(x, y, "Name: " + name);
	printScript(x, y, "Level: " + to_string(level));
	printScript(x, y, "HP: " + to_string(HP) + "/" + to_string(maxHP));
	printScript(x, y, "MP: " + to_string(MP));
	printScript(x, y, "Attack: " + to_string(attack));
	printScript(x, y, "Exp: " + to_string(exp));
	printScript(x, y, "Exp: " + to_string(gold));
	levelUp();
}

void Character::levelUp() {
	while (exp >= 100) {
		int x = 23;
		int y = 15;
		level++;
		exp %= 100;

		maxHP = maxHP + 20;
		maxMP = maxMP + 10;
		attack = attack + 5;
		HP = maxHP;
		setColor(yellow, black);
		printScript(x, y, "레벨업!        ");
		printScript(x, y, "Name: " + name);
		printScript(x, y, "Level: " + to_string(level));
		printScript(x, y, "HP: " + to_string(HP) + "/" + to_string(maxHP));
		printScript(x, y, "MP: " + to_string(MP));
		printScript(x, y, "Attack: " + to_string(attack));
		printScript(x, y, "Exp: " + to_string(exp) + "     ");
		printScript(x, y, "Exp: " + to_string(gold));
		setColor(white, black);
	}
	return;
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
}

void Character::visitShop() {
	bool exitShop = false;
	Shop* shop = new Shop;
	while (!exitShop){
		int x, y;
		int choice;
		choice = shop->shopMenuSelect();
		switch (choice) {
		case 1:
			x = 66;
			y = 12;
			for (int i = 0; i < 7; i++) {
				printScript(x, y, "                               ");
			}
			x = 96;
			y = 7;
			printScript(x, y, "판매하기");
			x = 70;
			y = 7;
			setColor(red, blue);
			printScript(x, y, "구매하기");
			setColor(white, black);
			shop->displayItem();
			shop->buyItem(shop->shopItemSelect(), this);
			break;
		case 2:
			x = 66;
			y = 12;
			for (int i = 0; i < 7; i++) {
				printScript(x, y, "                               ");
			}
			x = 70;
			y = 7;
			printScript(x, y, "구매하기");
			x = 96;
			y = 7;
			setColor(red, blue);
			printScript(x, y, "판매하기");
			setColor(white, black);
			displayInventory();
			shop->sellItem(shop->shopItemSelect(), this);
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

void Character::displayInventory()
{
	int x = 66;
	int y = 12;
	for (int i = 0; i < 7; i++) {
		printScript(x, y, "                               ");
	}
	y = 12;
	printScript(x, y, "자네의 물품을 살펴보지");
	int num = 1;
	y = 15;
	for (Item* item : inventory) {

		printScript(x, y, "[" + to_string(num) + "]" + item->getName() + "  가격:" + to_string(static_cast<int>(item->getPrice() * 0.6)));
		num++;
	}
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
}

vector<Item*>& Character::getInventory()
{
	return inventory;
}

void Character::addItem(Item* item) {
	if (item != nullptr) {
		inventory.push_back(item);
	}
}

int Character::getGold() {
	return gold;
}

void Character::setGold(int gold) {

	this->gold += gold;
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
