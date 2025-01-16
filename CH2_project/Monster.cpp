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
void Orc::speak()
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
        cout << "아무것도 보고싶지 않아.." << endl;;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "수군수군…수군수군…" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "시끄러워..! 조용히… 조용히해!!!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "운동…건강…프로틴…!!" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "내 꿈은…?" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "흑흑…" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
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
        cout << "여기 까지 오면서 기분은 좀 어땠나?" << endl;
        cout << "아직도 ”그것”에 의존하며 살고있는겐가?" << endl;
        cout << "옳은 일을 했을거라 믿는다." << endl;
        cout << "“의지”가 있었다면 말이야" << endl;
    }
    else {
        cout << name << ":내가 지다니.." << endl;
    }
}