#pragma once
#include "Item.h"
#include <vector>
class Inventory
{
public:
	Inventory();
	~Inventory();
	void AddItem(Item* item);
	void RemoveItem(unsigned int itemIndex);
	Item* GetItem(unsigned int itemIndex);
	void SortInventory(uint8_t itemTag);
private :
	std::vector<Item*> inventory;
};

