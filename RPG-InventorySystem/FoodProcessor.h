#pragma once
#include <vector>
#include "Item.h"
#include "Material.h"
class FoodProcessor
{
public :
	FoodProcessor();
	~FoodProcessor();
	Item* CookItem();

private :
	std::vector<Item*> mPot;
};

