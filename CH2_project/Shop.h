#pragma once
#include <vector>
#include "Character.h"

class Character;
class Item;

using namespace std;

class Shop {
private:
	vector<Item*> availableItems;

public:
	Shop();
	~Shop();
	void displayItem();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
	int shopMenuSelect();
	int shopItemSelect();
};
