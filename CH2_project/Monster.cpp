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
        cout << "죽여버리겠다!" << endl;
    }
    else {
        cout << "내가 지다니.." << endl;
    }
}

void Goblin::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
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
void Orc::speak()
{
    if (health > 0) {
        cout << name << ":싸움을 준비하라!" << endl;
    }
    else {
        cout << name << ":너를 이길수없다.." << endl;
    }
}

void Orc::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
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

void Troll::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
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

void BossMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

BlindMonster::BlindMonster(int level) : name("BlindMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void BlindMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

EyesMonster::EyesMonster(int level) : name("EyesMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void EyesMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

BigEaredMonster::BigEaredMonster(int level) : name("BigEaredMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void BigEaredMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

PerforatedMonster::PerforatedMonster(int level) : name("PerforatedMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void PerforatedMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

ChildMonster::ChildMonster(int level) : name("ChildMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void ChildMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

CryingMonster::CryingMonster(int level) : name("CryingMonster") {
    health = level * (20 + rand() % 11);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void CryingMonster::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}

FacelessMan::FacelessMan(int level) : name("FacelessMan") {
    health = level * (20 + rand() % 11);
    attack = level * (5 + rand() % 6);
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
        cout << name << ":죽여버리겠다!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}

void FacelessMan::monsterText() {
    int x = 80;
    int y = 5;
    printScript(x, y, "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤");
    printScript(x, y, "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⣿");
    printScript(x, y, "⢸⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿");
    gotoxy(82, 6);
    speak();
}
