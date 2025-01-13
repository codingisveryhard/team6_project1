#pragma once
#include <string>
#include "Character.h"

using namespace std;

// 전방 선언
class Character;

// 추상 클래 Item
class Item {
protected:
	string name; // 아이템 이름
	int price; //아이템 가격

public:
	Item(const string& name, int price) : name(name), price(price) {} // 생성자
    virtual ~Item() {} // 가상 소멸자

	virtual string getName() const;  // 아이템 이름 반환
	virtual void use(Character* character) = 0; // 캐릭터에게 아이템 사용 (순수 가상함수)
	virtual int getPrice() = 0; // 아이템 가격 반환
	
};

// 체력회복 아이템 : MorPhine
class MorPhinePotion : public Item {
private:
	int healthRestore; // 회복량
	

public:
	MorPhinePotion() : Item("Morphine", 10), healthRestore(25){} // 초기화 -> 가격 10 회복량 25회복 설정
	void use(Character* character) override;
	int getPrice();
};

class CocainePotion : public Item {
private:
	int attackPower; // 공격력

public:
	CocainePotion() : Item("CocainePotion", 20), attackPower(10){} // 초기화 -> 가격 20 공격력 10증가 설정
	void use(Character* character) override;
	int getPrice();
};

class HeroinPotion : public Item {
private:
	int healthRestore; // 회복량

public:
	HeroinPotion() : Item("HeroinPotion", 20), healthRestore(50){} // 초기화 -> 가격 20 회복량 50회복 설정
	void use(Character* character) override;
	int getPrice();
};

class LSDPotion : public Item {
private:
	int healthRestore; // 회복량
	int attackPower; // 공격력
public:
	LSDPotion() : Item("LSDPotion", 40), healthRestore(50), attackPower(10){} // 초기화 -> 가격 40, 회복량 50, 공격력 10 증가
	void use(Character* character) override;
	int getPrice();
};


class IVbeltWeapon : public Item {
private:
	int attackPower; // 공격력

public:
	IVbeltWeapon() : Item("IVbeltWeapon", 0), attackPower(10){} // 초기화 -> 가격0, 공격력 10증가
	void use(Character* character) override;
	int getPrice();
};


