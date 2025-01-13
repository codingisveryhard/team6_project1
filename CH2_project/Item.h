#pragma once
#include <string>
#include "Character.h"

using namespace std;

// ���� ����
class Character;

// �߻� Ŭ�� Item
class Item {
protected:
	string name; // ������ �̸�
	int price; //������ ����

public:
	Item(const string& name, int price) : name(name), price(price) {} // ������
    virtual ~Item() {} // ���� �Ҹ���

	virtual string getName() const {
		return name;
	} // ������ �̸� ��ȯ
	virtual void use(Character* character) = 0; // ĳ���Ϳ��� ������ ��� (���� �����Լ�)
	virtual int getPrice() const {
		return price;
	} // ������ ���� ��ȯ
	
};

// ü��ȸ�� ������ : MorPhine
class MorPhinePotion : public Item {
private:
	int healthRestore; // ȸ����
	

public:
	MorPhinePotion(); : Item("Morphine", 25), healthRestore(25){} // �ʱ�ȭ
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
