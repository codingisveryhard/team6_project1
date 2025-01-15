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
    system("cls");
    cout << endl << "전투가 시작된다!" << endl;
    Monster* monster = generateMonster(player->getLevel());

    // 몬스터 정보 출력
    cout << "몬스터 등장: " << monster->getName();
    cout << "체력: " << monster->getHP() << ", 공격력: " << monster->getAttack() << endl << endl;

    monster->speak(); // 몬스터가 처음 등장할 때 대사 출력 수정

    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        cout << endl << i << " 번째 턴!" << endl;
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        cout << "플레이어가 공격! " << monster->getName() << "의 체력: " << monster->getHP() << endl;
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {
            cout << monster->getName() << "를 처치했습니다!" << endl << endl;

            monster->speak(); // 몬스터가 죽기 전 대사 출력 수정

            player->setExp(50);
            player->displayStatus();
            player->setGold(player->getLevel() * 10);
            Item* dropedItem = monster->dropItem();
            if (dropedItem != nullptr) {
                cout << "아이템을 획득하셨습니다." << endl << "획득한 아이템: " << dropedItem->getName() << endl;
                player->addItem(dropedItem);
            }
            wait();
            system("cls");
            player->visitShop();
            break;
        }

        // 몬스터 공격
        cout << "몬스터가 공격!" << endl;
        player->takeDamage(monster->getAttack());
        
        // 플레이어 사망 시
        if (player->getHP() <= 0) {
            break;
        }
        if (player->getHP() < player->getMaxHP()*0.5) {
            player->useItem("Morphine");
        }
        wait();

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
