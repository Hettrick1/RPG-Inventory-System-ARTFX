#pragma once

#include "ItemType.h"

#include <iostream>

class Item
{
public:
	Item(std::uint8_t t, int p, std::string n);
	~Item();
	virtual std::uint8_t GetType() = 0;
protected:
	std::string mName;
	std::uint8_t mType;
	int mPrice;
};

