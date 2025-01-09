#include <crtdbg.h>
#include "Character.h"
#include "GameManager.h"
#include "Monster.h"

using namespace std;

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    cout << "캐릭터의 이름을 입력해 주세요." << endl << "이름: ";
    string name;
    getline(cin, name);
    // 싱글턴 인스턴스 생성
    Character* player = Character::getInstance(name);

    // GameManager 인스턴스 생성
    GameManager gameManager;

    cout << "===== 캐릭터 생성 =====" << endl;
    player->displayStatus();
    while (player->getLevel() != 10 && player->getHP() != 0) {
        gameManager.battle(player);
    }

    return 0;
}