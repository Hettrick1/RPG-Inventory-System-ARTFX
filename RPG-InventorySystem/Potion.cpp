#include "Potion.h"



Potion::Potion(std::uint8_t itemType, int price, std::string name, std::uint8_t potionType) : Item(itemType, price, name)
{
	mPotionType = potionType;
}

Potion::~Potion()
{
}

void Potion::Sell()
{
}
