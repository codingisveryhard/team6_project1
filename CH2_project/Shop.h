#pragma once
#include <vector>
#include "Character.h"

class Shop {
private:
	vector<Item*> availableItems;

public:
	Shop();
	void displayItem();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
};
