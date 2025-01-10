#include "Shop.h"

class Character;

Shop::Shop() {
	availableItems.push_back(new HealthPotion());
	availableItems.push_back(new HealthPotion());
}

Shop::~Shop() {
	for (Item* item : availableItems) {
		delete item;
	}
}

void Shop::displayItem(){
	cout << "이런 물건이 있소." << endl;
	for (Item* item : availableItems) {

		cout << item->getName() << endl;
	}
}

void Shop::buyItem(int index, Character* player) {
	if (index < 0 || index >= availableItems.size()) {
		cout << "소지하고 있지 않은 아이템입니다." << endl;
		return;
	}

	Item* item = availableItems[index];
	if (player->getGold() >= item->getPrice()) {
		player->addItem(item);
		player->setGold(item->getPrice() * -1);
	}
	else cout << "돈이 부족하오만" << endl;
}

void Shop::sellItem(int index, Character* player)
{

	vector<Item*>& inventory = player->getInventory();
	if (index < 0 || index >= inventory.size()) {
		cout << "잘못된 아이템 번호입니다." << endl;
		return;
	}
	Item* item = inventory[0];
	player->setGold(item->getPrice()*0.6);
	cout << item->getName() << item->getPrice() * 0.6<< "만큼 받고 팔았습니다." << endl;
	inventory.erase(inventory.begin() + 0);
	delete item;
}
