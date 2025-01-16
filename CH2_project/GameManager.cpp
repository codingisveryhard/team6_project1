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
    else if (randomMonster == 3) {
        return new BlindMonster(level); // 몬스터 추가 0116
    }
    else if (randomMonster == 4) {
        return new EyesMonster(level);
    }
    else if (randomMonster == 5) {
        return new BigEaredMonster(level);
    }
    else if (randomMonster == 6) {
        return new PerforatedMonster(level);
    }
    else if (randomMonster == 7) {
        return new ChildMonster(level);
    }
    else if (randomMonster == 8) {
        return new CryingMonster(level);
    }
    else if (randomMonster == 9) {
        return new FacelessMan(level);
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
<<<<<<< Updated upstream
    cout << "몬스터 등장: " << monster->getName();
    cout << "체력: " << monster->getHP() << ", 공격력: " << monster->getAttack() << endl << endl;
=======

    script.printbattleLog("몬스터 등장: " + monster->getName());
    script.printbattleLog("체력: " + to_string(monster->getHP()) + ", 공격력: " + to_string(monster->getAttack()));
    gotoxy(15, 4);
    cout << monster->getName();

    monster->monsterText(); // 몬스터가 처음 등장할 때 대사 출력 수정
   
    //주인공 대사 0116
    if (monster->getName() == "BlindMonster") {
        cout << "이게... 무슨 일이지? 너는..?" << endl;
        cout << "못알아듣는건가..? 뭐..뭐야...으아악!!" << endl;
    }
    else if (monster->getName() == "EyesMonster") {
        cout << "어디서 이런소리가 들리는거지?" << endl;
        cout << "이 소리들은.." << endl;
    }
    else if (monster->getName() == "EaredMoster") {
        cout << "멀 조용히 하라는거야 아무말도 안했는데..." << endl;
        cout << "귀가 커서 예민한걸까?" << endl;
        cout << "조용히 접근해야겠어" << endl;
    }
    else if (monster->getName() == "PerforatedMonster") {
        cout << "으악! 몸에 구멍이 나있어??!!!" << endl;
        cout << "이 녀석은 또 어떻게 해치워야 하는걸까.." << endl;
        cout << "일단 시도해보자!" << endl;
    }
    else if (monster->getName() == "ChildMonster") {
        cout << "그건 다 옛날 얘기일뿐이야.." << endl;
    }
    else if (monster->getName() == "CryingMonster") {
        cout << "이 녀석은 상태가 조금 다른데..?" << endl;
        cout << "조심해야겠어" << endl;
    }
    else if (monster->getName() == "FacelessMan") {
        cout << "그것?" << endl;
        cout << "그것이 의미하는게 뭐지..?" << endl;
        cout << "내 의지는 지금 여길 벗어나는 것 뿐이야!" << endl;
    }
    
>>>>>>> Stashed changes

    for (int i = 1; monster->getHP() > 0 && player->getHP() > 0; i++) {
        cout << endl << i << " 번째 턴!" << endl;
        // 플레이어 공격
        monster->takeDamage(player->getAttack());
        cout << "플레이어가 공격! " << monster->getName() << "의 체력: " << monster->getHP() << endl;
        // 몬스터 처치 시
        if (monster->getHP() <= 0) {
<<<<<<< Updated upstream
            cout << monster->getName() << "를 처치했습니다!" << endl << endl;
            player->setExp(50);
=======

            script.printbattleLog(monster->getName() + "를 처치했습니다!");
            player->setExp(50);                         // 경험치 획득량
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
                cout << "이것들에 정체에 대해 이제 조금씩 실마리가 잡히는것 같아" << endl;
                cout << "더 나아가보자" << endl;
            }
            else if (monster->getName() == "ChildMonster") {
                cout << "이렇게 쉽게 쓰러질 줄 알았다면 조금 더 오래 즐길 걸" << endl;
                cout << "재미없어" << endl;
            }
            else if (monster->getName() == "CryingMonster") {
                cout << "칫...생각보다 별 거 없잖아?" << endl;
                cout << "이제는 아무도 날 이길 수 없어" << endl;
            }
            else if (monster->getName() == "FacelessMan") {
                cout << "휴우...드디어 저 문 턱만 넘으면 이곳에서 벗어 날 수 있어" << endl;
                cout << "세상 밖으로 나가자" << endl;
            }

>>>>>>> Stashed changes
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
            player->useItem(0);
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
