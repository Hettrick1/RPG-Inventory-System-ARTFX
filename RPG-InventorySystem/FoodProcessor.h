#pragma once
#include <vector>
#include "Item.h"
#include "Material.h"
#include "FoodType.h"
class FoodProcessor
{
public :
	FoodProcessor();
	~FoodProcessor();
	Item* CookItem();
	void AddItemToPot(Material* itemToAdd);
	void RemoveElementToPot(int index);

private :
	std::vector<Material*> mPot;
	bool mCanAddToPot;
	uint8_t mActualRecipie;
};

