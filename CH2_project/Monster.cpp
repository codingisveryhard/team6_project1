#include "Monster.h"
#include <iostream> //수정사항 250115
using namespace std;//수정사항 250115

Goblin::Goblin(int level) : name("Goblin") {
    health = level * (20 + rand() % 11);
    attack = level * (5 + rand() % 6);
}

string Goblin::getName() {
    return name;
}

int Goblin::getHP() {
    return health;
}

int Goblin::getAttack() {
    return attack;
}

void Goblin::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* Goblin::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void Goblin::speak()
{
    if (health > 0) {
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

Orc::Orc(int level) : name("Orc") {
    health = level * (20 + rand() % 11);
    attack = level * (5 + rand() % 6);
}

string Orc::getName() {
    return name;
}

int Orc::getHP() {
    return health;
}

int Orc::getAttack() {
    return attack;
}

void Orc::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* Orc::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}
//수정사항 250115
void Orc:: speak()
{
    if (health > 0) {
        cout << name << ":싸움을 준비하라!" << endl;
    }
    else {
        cout << name << ":너를 이길수없다.." << endl;
    }
}

Troll::Troll(int level) : name("Troll") {
    health = level * (20 + rand() % 11);
    attack = level * (5 + rand() % 6);
}

string Troll::getName() {
    return name;
}

int Troll::getHP() {
    return health;
}

int Troll::getAttack() {
    return attack;
}

void Troll::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;         // 체력이 0밑으로 떨어지면 0으로 출력
}

Item* Troll::dropItem() {
    int dropRate = rand() % 10;
    if (dropRate < 3) {
        return new MorPhinePotion(morphinePotion);
    }
    return nullptr;
}

//수정사항 250115
void Troll::speak()
{
    if (health > 0) {
        cout << name << ":박살내주마!" << endl;
    }
    else {
        cout << name << ":내가 질 줄이야.." << endl;
    }
}

BossMonster::BossMonster(int level) : name("BossMonster") {
    health = level * (20 + rand() % 11);
    attack = level * (5 + rand() % 6);
}

string BossMonster::getName()
{
    return name;
}

int BossMonster::getHP()
{
    return health;
}

int BossMonster::getAttack()
{
    return attack;
}

void BossMonster::takeDamage(int damage)
{
    health -= damage;
}

Item* BossMonster::dropItem()
{
    return nullptr;
}
//수정사항 250115
void BossMonster::speak()
{
    if (health > 0) {
        cout << name << ":너는 나를 이길수 없다!" << endl;
    }
    else {
        cout << name << ":이럴수가.. 내가 패배하다니.." << endl;
    }
}