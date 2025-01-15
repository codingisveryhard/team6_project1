#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <memory>



class IObserver {
public:
	virtual ~IObserver() = default;
	virtual void updateHP(int HP, int change, bool isHeal) = 0;
	virtual void updateGold(int gold, int change, bool isSpend) = 0;
};

