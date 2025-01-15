#pragma once
#include "Observer.h"
#include <iostream>

using namespace std;


// UI 업데이트 옵저버
class HealthBar : public IObserver {
public:
    void updateHP(int HP, int change, bool isHeal) override;
    void updateGold(int gold, int change, bool isSpend) override;
};

class Moneybag : public IObserver {
public:
    void updateHP(int HP, int change, bool isHeal) override;
    void updateGold(int gold, int change, bool isSpend) override;
};
