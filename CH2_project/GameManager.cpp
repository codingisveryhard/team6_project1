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

BossMonster* GameManager::generateBossMonster(int level)
{
    return nullptr;
}

void GameManager::battle(Character* player)
{
    system("cls");
    battlePhase();
    stageDraw(player->getLevel());
    Script script;
    script.printbattleLog("전투가 시작된다!");
    Monster* monster = generateMonster(player->getLevel());

    // 몬스터 정보 출력
    cout << "몬스터 등장: " << monster->getName();
    cout << "체력: " << monster->getHP() << ", 공격력: " << monster->getAttack() << endl << endl;

    script.printbattleLog("몬스터 등장: " + monster->getName());
    script.printbattleLog("체력: " + to_string(monster->getHP()) + ", 공격력: " + to_string(monster->getAttack()));
    setColor(brown, black);
    gotoxy(15, 4);
    cout << monster->getName();
    setColor(white, black);

    monster->monsterText(); // 몬스터가 처음 등장할 때 대사 출력 수정
  
    if (monster->getName() == "BlindMonster") {
        cout << "이게... 무슨 일이지? 너는..?" << endl;
        cout << "못알아듣는건가..? 뭐..뭐야...으아악!!" << endl;
    }
    else if (monster->getName() == "EyesMonster") {
        cout << "어디서 이런소리가 들리는거지?" << endl;
        cout << "이 소리들은.." << endl;
    }
    else if (monster->getName() == "EaredMoster") {
        cout << "..............." << endl;
        cout << "조용히 접근해야겠어" << endl;
    }
    else if (monster->getName() == "PerforatedMonster") {
        cout << "으악! 몸에 구멍이 나있어??!!!" << endl;
        cout << "이 녀석은 또 어떻게 해치워야 하는걸까.." << endl;
        
    }
    else if (monster->getName() == "ChildMonster") {
        cout << "그건 다 옛날 얘기일뿐이야.." << endl;
    }
    else if (monster->getName() == "CryingMonster") {
        cout << "울고있잔아..?" << endl;
        cout << "....일단 생각하지 말자" << endl;
    }
    else if (monster->getName() == "FacelessMan") {
        cout << "많은것을 겪었고" << endl;
        cout << "많은것을 보았죠" << endl;
        cout << "“의지”로 지금에 이르렀습니다." << endl;
    }
  
    wait();
  
    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        script.printbattleLog(to_string(i) + " 번째 턴!");
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        script.printbattleLog("플레이어가 공격! " + monster->getName() + "의 체력: " + to_string(monster->getHP()));
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {
            script.printbattleLog(monster->getName() + "를 처치했습니다!");
            player->setExp(100);                         // 경험치 획득량
            player->setGold(player->getLevel() * 10);   // 골드 획득량

            monster->speak(); // 몬스터가 죽은 후 대사 출력 수정
            
            // 주인공 대사 0116
            if (monster->getName() == "BlindMonster") {
                cout << "갑자기 공격하다니 위험했어" << endl;
                cout << "빨리 이곳을 나가자" << endl;
            }
            else if (monster->getName() == "EyesMonster") {
                cout << "어째서 괴물들을 만나게 된거지...?" << endl;
                cout << "앞으로 이런 녀석들이 얼마나 더 있는걸까" << endl;
            }
            else if (monster->getName() == "EaredMoster") {
                cout << "이제...더는 불안해 하지 않아도 돼" << endl;
            }
            else if (monster->getName() == "PerforatedMonster") {
                cout << "더 나아가보자" << endl;
            }
            else if (monster->getName() == "ChildMonster") {
                cout << "모든것이 끝나가고 있다." << endl;
            }
            else if (monster->getName() == "CryingMonster") {
                cout << "당신은 여정의 끝이 보이는 듯 하다." << endl;
            }
            else if (monster->getName() == "FacelessMan") {
                cout << "모든것이 끝나고 당신은 문앞에 서게된다 " << endl;
            }

            monster->monsterText(); // 몬스터가 죽기 전 대사 출력 수정
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

void GameManager::stageDraw(int level) {
    if (level == 1) stage1();
    else if (level == 2) stage2();
    else if (level == 3) stage3();
    else if (level == 4) stage4();
    else if (level == 5) stage5();
    else if (level == 6) stage6();
    else if (level == 7) stage7();
}
