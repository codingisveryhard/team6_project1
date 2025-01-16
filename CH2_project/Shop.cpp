#include "Shop.h"

class Character;

Shop::Shop() {
	availableItems.push_back(new MorPhinePotion());
	availableItems.push_back(new HeroinPotion());
}

Shop::~Shop() {				// 소멸자 잊지 않기
	for (Item* item : availableItems) {
		delete item;
	}
}

void Shop::displayItem(){
	int x = 66;
	int y = 12;
	printScript(x, y, "귀한 물건들이라네 한번 골라보게");
	int num = 1;
	y = 15;
	for (Item* item : availableItems) {

		printScript(x, y, "[" + to_string(num) + "]" + item->getName() + "  가격:" + to_string(item->getPrice()));
		num++;
	}
}

void Shop::buyItem(int index, Character* player) {
	int x = 66;
	int y = 12;
	for (int i = 0; i < 7; i++) {
		printScript(x, y, "                               ");
	}
	y = 12;
	if (index < 0 || index >= availableItems.size()) {
		printScript(x, y, "그런 물건은 없다네");
		y += 3;
		printScript(x, y, "다른 거래를 할텐가?");
		return;
	}

	Item* item = availableItems[index]->clone();
	if (player->getGold() >= item->getPrice()) {
		player->addItem(item);
		player->setGold(item->getPrice() * -1);
		printScript(x, y, item->getName() + "은 이제 자네의 것일세");
		y += 3;
		printScript(x, y, "다른 거래를 할텐가?");
		
	}
	else {
		printScript(x, y, "그 돈으로 뭘 구매하겠다는 건가?");
		y += 3;
		printScript(x, y, "다른 거래를 할텐가?");
	}
}

void Shop::sellItem(int index, Character* player)
{
	int x = 66;
	int y = 12;
	for (int i = 0; i < 7; i++) {
		printScript(x, y, "                               ");
	}
	y = 12;
	vector<Item*>& inventory = player->getInventory();
	if (index < 0 || index >= inventory.size()) {
		printScript(x, y, "그런 물건은 없다네");
		y += 3;
		printScript(x, y, "다른 거래를 할텐가?");
		return;
	}
	Item* item = inventory[0];
	player->setGold(static_cast<int>(item->getPrice()*0.6));
	printScript(x, y, "여기 " + to_string(static_cast<int>(item->getPrice() * 0.6)) + "gold 라네");
	y += 3;
	printScript(x, y, "다른 거래를 할텐가?");
	inventory.erase(inventory.begin() + 0);
	delete item;
}
