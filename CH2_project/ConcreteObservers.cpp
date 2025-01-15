#include "ConcreteObservers.h"

void HealthBar::updateHP(int HP, int change, bool isHeal) {
    if (isHeal) cout << "[UI] 플레이어의 체력이 회복되었습니다. 회복량: " << change << " 현재체력: " << HP << endl;
    else cout << "[UI] 플레이어의 체력이 감소하였습니다. 감소량: " << change << " 현재체력: " << HP << endl;
    if (HP <= 0) cout << "[UI] 플레이어의 체력이 0이 되어 캐릭터가 사망했습니다." << endl;
}

void HealthBar::updateGold(int gold, int change, bool isSpend) {
}

void Moneybag::updateHP(int HP, int change, bool isHeal) {
}

void Moneybag::updateGold(int gold, int change, bool isSpend) {
    if (isSpend) cout << "[UI] 골드를 획득하였습니다. 획득량: " << change << " 현재골드: " << gold << endl;
    else cout << "[UI] 골드를 소모하였습니다. 소모량: " << change << " 현재골드: " << gold << endl;
}
