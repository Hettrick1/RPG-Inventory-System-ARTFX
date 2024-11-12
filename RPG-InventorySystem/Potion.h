#pragma once

#include "Item.h"
#include "ItemType.h"
#include "PotionType.h"

class Potion : public Item
{
public:
	Potion(std::uint8_t itemType, int price, std::string name, std::uint8_t potionType);
	~Potion();
	void Sell() override;
protected:
	std::uint8_t mPotionType;
};

