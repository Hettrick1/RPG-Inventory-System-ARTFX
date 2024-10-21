#pragma once

#include "Item.h"
#include "ItemType.h"
#include "IFlammable.h"

class Material : public Item, IFlammable
{
public:
	Material(std::uint8_t type, int price, std::string name);
	~Material();
protected:

};

