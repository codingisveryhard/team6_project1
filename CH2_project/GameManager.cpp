#include "GameManager.h"

Monster* GameManager::generateMonster(int level)
{
    int randomMonster = rand() % 3;
    if (randomMonster == 0) {
        return new Goblin(level);
    }
    else if (randomMonster == 1) {
        return new Orc(level);
    }
    else if(randomMonster == 2) {
        return new Troll(level);
    }
}

BossMonster* GameManager::generateBossMonster(int level)
{
    return nullptr;
}

void GameManager::battle(Character* player)
{
    cout << endl << "전투를 시작합니다!" << endl;

    Monster* monster = generateMonster(player->getLevel());

    // 몬스터 정보 출력
    cout << "몬스터 등장: " << monster->getName();
    cout << "체력: " << monster->getHP() << ", 공격력: " << monster->getAttack() << endl << endl;

    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        cout << endl << i << " 번째 턴!" << endl;
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        cout << "플레이어가 공격! " << monster->getName() << "의 체력: " << monster->getHP() << endl;
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {
            cout << monster->getName() << "를 처치했습니다!" << endl << endl;
            player->setExp(50);
            player->displayStatus();
            player->setGold(player->getLevel() * 10);
            Item* dropedItem = monster->dropItem();
            if (dropedItem != nullptr) {
                cout << "아이템을 획득하셨습니다." << endl << "획득한 아이템: " << dropedItem->getName() << endl;
                player->addItem(dropedItem);
            }

            player->visitShop();
            break;
        }

        // 몬스터 공격
        player->takeDamage(monster->getAttack());
        cout << "몬스터가 공격! 플레이어 체력: " << player->getHP() << endl;
        // 플레이어 사망 시
        if (player->getHP() <= 0) {
            cout << "플레이어가 사망했습니다!" << endl;
            break;
        }
        if (player->getHP() < player->getMaxHP()*0.2) {
            player->useItem("HealthPotion");
        }

    }

    // 메모리 해제
    delete monster;
}

void GameManager::visitShop(Character* player)
{
}

void GameManager::displayInventory(Character* player)
{
}
