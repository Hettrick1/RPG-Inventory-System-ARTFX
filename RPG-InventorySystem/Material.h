#pragma once

#include "Item.h"
#include "ItemType.h"
#include "FoodType.h"
#include "IFlammable.h"
#include "IBackable.h"

class Material : public Item, public IFlammable, public IBackable
{
public:
	Material(std::uint8_t itemType, std::uint8_t foodType, int price, std::string name);
	~Material();
	uint8_t GetFoodType();
	void Burn(); // the function from the IFlammable interface that can handle the spread fire
	int Sell() override;
	bool canCraft() override;
protected:
	std::uint8_t mFoodType;
};

