#define _CRTDBG_MAP_ALLOC           // 메모리 누수 확인용
#include <stdlib.h>                 // 메모리 누수 확인용
#include <crtdbg.h>                 // 메모리 누수 확인용
#include "Character.h"
#include "GameManager.h"
#include "Monster.h"
#include <cstdlib>  // malloc, free
#include "background.h"
#include "Utility.h"
#include "Observer.h"
#include "ConcreteObservers.h"
#include "Script.h"

//// 'new' 연산자를 오버라이드하여 메모리 할당을 추적
//void* operator new(size_t size) {
//    void* ptr = malloc(size);  // 메모리 할당
//    if (ptr) {
//        std::cout << "Allocated memory at: " << ptr << ", size: " << size << std::endl;
//    }
//    else {
//        std::cout << "Memory allocation failed!" << std::endl;
//    }
//    return ptr;  // 할당된 메모리 주소 반환
//}
//
//// 선택적으로, 메모리 해제 시에도 로그를 출력하려면 'delete'도 오버라이드
//void operator delete(void* ptr) noexcept {
//    if (ptr) {
//        std::cout << "Deallocated memory at: " << ptr << std::endl;
//        free(ptr);  // 메모리 해제
//    }
//}
using namespace std;


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);   // 메모리 누수 확인용
    // _CrtSetBreakAlloc(661);   // 메모리 누수 확인용 (브레이크 포인트 설정)
    
    eraseCursor();      // 커서 지워버리기
    system("mode con cols=120 lines=40 | title 창 제목");  // 콘솔 사이즈 정하기
    title();                // 타이틀 화면 보이게하기
    menuDraw();         // 메뉴 화면
    system("cls");      // 콘솔 창을 깨끗하게 만드는 코드
    
    Script script;
    script.start();
    cout << "캐릭터의 이름을 입력해 주세요." << endl << "이름: ";
    string name;
    getline(cin, name);
    // 싱글턴 인스턴스 생성
    Character* player = Character::getInstance(name);

    auto healthBar = make_shared<HealthBar>();
    player->Attach(healthBar);

    // GameManager 인스턴스 생성
    GameManager gameManager;

    cout << "===== 캐릭터 생성 =====" << endl;
    player->displayStatus();
    // 10레벨이 될 때까지 전투
    while (player->getLevel() != 3 && player->getHP() != 0) {
        gameManager.battle(player);
    }
    Character::destroyInstance();
    

    // 몬스터 생성 추가 수정사항 250115
    Goblin goblin(1);
    Orc orc(2);
    Troll troll(3);
    BossMonster boss(5);

    // Goblin 대사 출력
    cout << "Goblin 등장!" << endl;
    goblin.speak();

    // Goblin 공격 받음
    goblin.takeDamage(50);
    cout << "Goblin이 공격을 받았습니다! (HP: " << goblin.getHP() << ")" << endl;
    goblin.speak();

    // Orc 대사 출력
    cout << "\nOrc 등장!" << endl;
    orc.speak();

    // Troll 대사 출력
    cout << "\nTroll 등장!" << endl;
    troll.speak();

    // Boss 대사 출력
    cout << "\nBossMonster 등장!" << endl;
    boss.speak();
    
    return 0;
}