#include "GameManager.h"

Monster* GameManager::generateMonster(int level)
{
    //int randomMonster = rand() % 3;
    //if (randomMonster == 0) {
    //    return new Goblin(level);
    //}
    //else if (randomMonster == 1) {
    //    return new Orc(level);
    //}
    //else if(randomMonster == 2) {
    //    return new Troll(level);
    //}
    if (level == 1) {
        return new BlindMonster(level); // 몬스터 추가 0116
    }
    else if (level == 2) {
        return new EyesMonster(level);
    }
    else if (level == 3) {
        return new BigEaredMonster(level);
    }
    else if (level == 4) {
        return new PerforatedMonster(level);
    }
    else if (level == 5) {
        return new ChildMonster(level);
    }
    else if (level == 6) {
        return new CryingMonster(level);
    }
    else if (level == 7) {
        return new FacelessMan(level);
    }
}


void GameManager::battle(Character* player)
{
    system("cls");
    battlePhase();
    stageDraw(player->getLevel());
    player->displayBattleBar();
    Script script;
    script.printbattleLog("전투가 시작된다!");
    Monster* monster = generateMonster(player->getLevel());

    // 몬스터 정보 출력
    cout << "몬스터 등장: " << monster->getName();

    script.printbattleLog("몬스터 등장: " + monster->getName());
    script.printbattleLog("체력: " + to_string(monster->getHP()) + ", 공격력: " + to_string(monster->getAttack()));
    
    setColor(brown, black);
    gotoxy(10, 4);
    cout << monster->getName();
    setColor(white, black);

    
    script.playerStartScript(monster->getName());
    wait();
    monsterDraw(player->getLevel());
    monster->monsterText(); // 몬스터가 처음 등장할 때 대사 출력 수정
    wait();
  
    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        player->displayBattleBar();
        script.printbattleLog(to_string(i) + " 번째 턴!");
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        script.printbattleLog("플레이어가 공격! " + monster->getName() + "의 체력: " + to_string(monster->getHP()));
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {
            script.printbattleLog(monster->getName() + "를 처치했습니다!");
            player->setExp(100);                         // 경험치 획득량
            player->setGold(player->getLevel() * 10);   // 골드 획득량

            monster->monsterText(); // 몬스터가 죽기 전 대사 출력 수정

            script.playerWinScript(monster->getName());

            wait();
            player->displayStatus();
            Item* dropedItem = monster->dropItem();
            if (dropedItem != nullptr) {
                script.printbattleLog("아이템을 획득하셨습니다. 획득한 아이템: " + dropedItem->getName());
                player->addItem(dropedItem);
            }
            wait();
            choiceWindow();
            int shop = battleMenu();
            if (shop == 0) {
                system("cls");
                shopWindow();
                player->visitShop();
            }
            break;
        }

        // 몬스터 공격
        script.printbattleLog("몬스터가 공격!   " + to_string(monster->getAttack()) + "만큼의 공격을 받았다.");
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

void GameManager::stageDraw(int level) {
    if (level == 1) stage1();
    else if (level == 2) stage2();
    else if (level == 3) stage3();
    else if (level == 4) stage4();
    else if (level == 5) stage5();
    else if (level == 6) stage6();
    else if (level == 7) stage7();
}

void GameManager::monsterDraw(int level) {
    if (level == 1) monsterImg1();
    else if (level == 2) monsterImg2();
    else if (level == 3) monsterImg3();
    else if (level == 4) monsterImg4();
    else if (level == 5) monsterImg5();
    else if (level == 6) monsterImg6();
    else if (level == 7) monsterImg7();
}