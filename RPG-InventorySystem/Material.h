#pragma once

#include "Item.h"
#include "ItemType.h"
#include "FoodType.h"
#include "IFlammable.h"
#include "IBackable.h"

class Material : public Item, IFlammable, IBackable
{
public:
	Material(std::uint8_t itemType, std::uint8_t foodType, int price, std::string name);
	~Material();
	uint8_t GetFoodType();
	void Burn();
	void Sell();
protected:
	std::uint8_t mFoodType;
};

