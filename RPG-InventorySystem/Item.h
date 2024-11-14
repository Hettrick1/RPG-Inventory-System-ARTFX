#pragma once
#include "ItemType.h"
#include <iostream>

class Item
{
public:
	Item(std::uint8_t t, int p, std::string n);
	~Item();
	std::uint8_t GetType();
	std::string GetName();
	virtual void Sell() = 0;
protected:
	std::string mName;
	std::uint8_t mType;
	int mPrice;
};

