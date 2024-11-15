#pragma once
#include <vector>
#include "Item.h"
#include "Material.h"
#include "Potion.h"

class Material;

class FoodProcessor
{
public :
	FoodProcessor();
	~FoodProcessor();
	Item* CookItem();
	void AddItemToPot(Material* itemToAdd);
	void PrintPot();

private :
	std::vector<Material*> mPot;
	bool mCanAddToPot;
	uint8_t mActualRecipie;
};

