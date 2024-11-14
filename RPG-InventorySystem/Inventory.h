#pragma once
#include "Item.h"
#include "Material.h"
#include "Potion.h"
#include "FoodProcessor.h"

#include <vector>
class Inventory
{
public:
	Inventory();
	~Inventory();
	void Init();
	void AddItem(Item* item);
	void RemoveItem(unsigned int itemIndex);
	Item* GetItem(unsigned int itemIndex);
	void PrintInventory();
	void SellItem(unsigned int itemIndex);
	void AddItemToPot(unsigned int itemIndex);
private :
	std::vector<Item*> mInventory;
	FoodProcessor* mCraftingTable;
	int mMoney;
};

