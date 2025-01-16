#include "Monster.h"
#include <iostream> //수정사항 250115
using namespace std;//수정사항 250115

// 사용하지 않는 몬스터 주석처리
//Goblin::Goblin(int level) : name("Goblin") {
//    health = level * (20 + rand() % 11);
//    attack = level * (5 + rand() % 6);
//}
//
//string Goblin::getName() {
//    return name;
//}
//
//int Goblin::getHP() {
//    return health;
//}
//
//int Goblin::getAttack() {
//    return attack;
//}
//
//void Goblin::takeDamage(int damage) {
//    health -= damage;
//    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
//}
//
//Item* Goblin::dropItem() {
//    int dropRate = rand() % 10;
//    if (dropRate < 3) {
//        return new MorPhinePotion(morphinePotion);
//    }
//    return nullptr;
//}
//
////수정사항 250115
//void Goblin::speak()
//{
//    if (health > 0) {
//        cout << "죽여버리겠다!" << endl;
//    }
//    else {
//        cout << "내가 지다니.." << endl;
//    }
//}
//
//void Goblin::monsterText() {
//    int x = 80;
//    int y = 5;
//    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
//    gotoxy(82, 6);
//    speak();
//}
//
//Orc::Orc(int level) : name("Orc") {
//    health = level * (20 + rand() % 11);
//    attack = level * (5 + rand() % 6);
//}
//
//string Orc::getName() {
//    return name;
//}
//
//int Orc::getHP() {
//    return health;
//}
//
//int Orc::getAttack() {
//    return attack;
//}
//
//void Orc::takeDamage(int damage) {
//    health -= damage;
//    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
//}
//
//Item* Orc::dropItem() {
//    int dropRate = rand() % 10;
//    if (dropRate < 3) {
//        return new MorPhinePotion(morphinePotion);
//    }
//    return nullptr;
//}
////수정사항 250115
//void Orc::speak()
//{
//    if (health > 0) {
//        cout << name << ":싸움을 준비하라!" << endl;
//    }
//    else {
//        cout << name << ":너를 이길수없다.." << endl;
//    }
//}
//
//void Orc::monsterText() {
//    int x = 80;
//    int y = 5;
//    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
//    gotoxy(82, 6);
//    speak();
//}
//
//Troll::Troll(int level) : name("Troll") {
//    health = level * (20 + rand() % 11);
//    attack = level * (5 + rand() % 6);
//}
//
//string Troll::getName() {
//    return name;
//}
//
//int Troll::getHP() {
//    return health;
//}
//
//int Troll::getAttack() {
//    return attack;
//}
//
//void Troll::takeDamage(int damage) {
//    health -= damage;
//    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
//}
//
//Item* Troll::dropItem() {
//    int dropRate = rand() % 10;
//    if (dropRate < 3) {
//        return new MorPhinePotion(morphinePotion);
//    }
//    return nullptr;
//}
//
////수정사항 250115
//void Troll::speak()
//{
//    if (health > 0) {
//        cout << name << ":박살내주마!" << endl;
//    }
//    else {
//        cout << name << ":내가 질 줄이야.." << endl;
//    }
//}
//
//void Troll::monsterText() {
//    int x = 80;
//    int y = 5;
//    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
//    gotoxy(82, 6);
//    speak();
//}
//
//BossMonster::BossMonster(int level) : name("BossMonster") {
//    health = level * (20 + rand() % 11);
//    attack = level * (5 + rand() % 6);
//}
//
//string BossMonster::getName()
//{
//    return name;
//}
//
//int BossMonster::getHP()
//{
//    return health;
//}
//
//int BossMonster::getAttack()
//{
//    return attack;
//}
//
//void BossMonster::takeDamage(int damage)
//{
//    health -= damage;
//}
//
//Item* BossMonster::dropItem()
//{
//    return nullptr;
//}
////수정사항 250115
//void BossMonster::speak()
//{
//    if (health > 0) {
//        cout << name << ":너는 나를 이길수 없다!" << endl;
//    }
//    else {
//        cout << name << ":이럴수가.. 내가 패배하다니.." << endl;
//    }
//}
//
//void BossMonster::monsterText() {
//    int x = 80;
//    int y = 5;
//    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
//    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
//    gotoxy(82, 6);
//    speak();
//}

BlindMonster::BlindMonster(int level) : name("눈을 가린 괴물") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string BlindMonster::getName() {
    return name;
}

int BlindMonster::getHP() {
    return health;
}

int BlindMonster::getAttack() {
    return attack;
}

void BlindMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* BlindMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void BlindMonster::speak()
{
    if (health > 0) {
        cout << "아무것도 보고싶지 않아.." << endl;;
    }
    else {
        cout << "너가.. 할 수 있을까..." << endl;
    }
}

void BlindMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

EyesMonster::EyesMonster(int level) : name("백개의 눈") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string EyesMonster::getName() {
    return name;
}

int EyesMonster::getHP() {
    return health;
}

int EyesMonster::getAttack() {
    return attack;
}

void EyesMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* EyesMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void EyesMonster::speak()
{
    if (health > 0) {
        cout << "(힐끗 힐끗)…(힐끗 힐끗)…" << endl;
    }
    else {
        cout << "눈이 감기며 편안해진 모습이다." << endl;
    }
}

void EyesMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀  ⠀⠀    ⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

BigEaredMonster::BigEaredMonster(int level) : name("귀 큰 괴물") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string BigEaredMonster::getName() {
    return name;
}

int BigEaredMonster::getHP() {
    return health;
}

int BigEaredMonster::getAttack() {
    return attack;
}

void BigEaredMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* BigEaredMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void BigEaredMonster::speak()
{
    if (health > 0) {
        cout << "시끄러워..! 조용히…" << endl;
        gotoxy(82, 7);
        setColor(red, black);
        cout << " 조용히해!!!" << endl;
        setColor(white, black);
    }
    else {
        cout << "날 미워하지 말아줘" << endl;
    }
}

void BigEaredMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

PerforatedMonster::PerforatedMonster(int level) : name("구멍 뚫린 괴물") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string PerforatedMonster::getName() {
    return name;
}

int PerforatedMonster::getHP() {
    return health;
}

int PerforatedMonster::getAttack() {
    return attack;
}

void PerforatedMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* PerforatedMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void PerforatedMonster::speak()
{
    if (health > 0) {
        cout << "운동…건강…프로틴…!!" << endl;
    }
    else {
        cout << "그 의지를 잊지마." << endl;
    }
}

void PerforatedMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

ChildMonster::ChildMonster(int level) : name("낯익은 어린아이") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string ChildMonster::getName() {
    return name;
}

int ChildMonster::getHP() {
    return health;
}

int ChildMonster::getAttack() {
    return attack;
}

void ChildMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* ChildMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void ChildMonster::speak()
{
    if (health > 0) {
        cout << "내 꿈은…?" << endl;
    }
    else {
        cout << "왠지 모르겠지만" << endl;
        gotoxy(82, 7);
        cout << "너라면 할 수 있어!" << endl;
    }
}

void ChildMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

CryingMonster::CryingMonster(int level) : name("친숙한 괴물") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6);
}

string CryingMonster::getName() {
    return name;
}

int CryingMonster::getHP() {
    return health;
}

int CryingMonster::getAttack() {
    return attack;
}

void CryingMonster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* CryingMonster::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void CryingMonster::speak()
{
    if (health > 0) {
        cout << "흑흑…" << endl;
    }
    else {
        cout << "언제나 널 사랑한단다." << endl;
    }
}

void CryingMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

FacelessMan::FacelessMan(int level) : name("얼굴없는 남자") {
    health = level * (20 + rand() % 11) * 2;
    attack = level * (5 + rand() % 6) * 2;
}

string FacelessMan::getName() {
    return name;
}

int FacelessMan::getHP() {
    return health;
}

int FacelessMan::getAttack() {
    return attack;
}

void FacelessMan::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* FacelessMan::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void FacelessMan::speak()
{
    if (health > 0) {
        gotoxy(82, 6);
        cout << "상태는 좀 어떤가?" << endl;
        gotoxy(82, 7);
        cout << "아직도 ”그것”에 " << endl;
        gotoxy(82, 8);
        cout << "의존하며 살고있는겐가?" << endl;
        wait();
        gotoxy(82, 6);
        cout << "옳은 일을 했을거라 믿는다. " << endl;
        gotoxy(82, 7);
        cout << "“의지”가 있었다면 말이야 " << endl;
        gotoxy(82, 8);
        cout << "                         " << endl;
    }
    else {
        gotoxy(82, 6);
        cout << "그동안 만나서 즐거웠네" << endl;
        gotoxy(82, 7);
        cout << "                    ";
    }
}

void FacelessMan::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    ⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}
