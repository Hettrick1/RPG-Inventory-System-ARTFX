#pragma once
#include "Item.h"
#include "ItemType.h"

class Weapon : public Item
{
public :
	Weapon(std::uint8_t type, int price, std::string name);
	~Weapon();
protected:
	float mDamages;
};

