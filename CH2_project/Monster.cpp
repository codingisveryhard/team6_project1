#include "Monster.h"

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
}Troll::Troll(int level) : name("Troll") {
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
