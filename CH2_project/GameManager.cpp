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
    battlePhase();
    Script script;
    script.printbattleLog("전투가 시작된다!");
    Monster* monster = generateMonster(player->getLevel());

    // 몬스터 정보 출력

    script.printbattleLog("몬스터 등장: " + monster->getName());
    script.printbattleLog("체력: " + to_string(monster->getHP()) + ", 공격력: " + to_string(monster->getAttack()));
    gotoxy(15, 4);
    cout << monster->getName();

    monster->speak(); // 몬스터가 처음 등장할 때 대사 출력 수정

    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        script.printbattleLog(to_string(i) + " 번째 턴!");
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        script.printbattleLog("플레이어가 공격! " + monster->getName() + "의 체력: " + to_string(monster->getHP()));
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {

            script.printbattleLog(monster->getName() + "를 처치했습니다!");
            player->setExp(50);                         // 경험치 획득량
            player->setGold(player->getLevel() * 10);   // 골드 획득량

            monster->speak(); // 몬스터가 죽기 전 대사 출력 수정

            player->displayStatus();
            Item* dropedItem = monster->dropItem();
            if (dropedItem != nullptr) {
                script.printbattleLog("아이템을 획득하셨습니다. 획득한 아이템: " + dropedItem->getName());
                player->addItem(dropedItem);
            }
            wait();
            shopWindow();
            player->visitShop();
            break;
        }

        // 몬스터 공격
        script.printbattleLog("몬스터가 공격!");
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
