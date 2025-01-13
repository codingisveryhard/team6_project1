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

	virtual string getName() const {
		return name;
	} // 아이템 이름 반환
	virtual void use(Character* character) = 0; // 캐릭터에게 아이템 사용 (순수 가상함수)
	virtual int getPrice() const {
		return price;
	} // 아이템 가격 반환
	
};

// 체력회복 아이템 : MorPhine
class MorPhinePotion : public Item {
private:
	int healthRestore; // 회복량
	

public:
	MorPhinePotion(); : Item("Morphine", 25), healthRestore(25){} // 초기화
	void use(Character* Character) override;
};

class CocainePotion : public Item {
private:
	string name;
	int healthRestore = 50;
	int price = 30;

public:
	CocainePotion();
	string getName();
	int getPrice();
	void use(Character* character);
};

class HeroinPotion : public Item {
private:
	string name;
	int healthRestore = 50;
	int price = 30;

public:
	HeroinPotion();
	string getName();
	int getPrice();
	void use(Character* character);
};

class LSDPotion : public Item {
private:
	string name;
	int healthRestore = 50;
	int price = 30;

public:
	LSDPotion();
	string getName();
	int getPrice();
	void use(Character* character);
};


class IVbeltWeapon : public Item {
private:
	string name;
	int attackBoost = 10;
	int price = 0;

public:
	IVbeltWeapon();
	string getName();
	int getPrice();
	void use(Character* character);
};
