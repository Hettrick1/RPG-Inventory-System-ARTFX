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
	virtual int Sell() = 0;
	bool HasTag(std::uint8_t tag);
protected:
	std::string mName;
	std::uint8_t mType;
	int mPrice;
};

