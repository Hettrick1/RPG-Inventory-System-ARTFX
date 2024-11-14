#include "Potion.h"



Potion::Potion(std::uint8_t itemType, int price, std::string name, std::uint8_t potionType) : Item(itemType, price, name)
{
	mPotionType = potionType;
}

Potion::~Potion()
{
}

int Potion::Sell()
{
	std::cout << std::endl << "You just sold a potion for : " << mPrice << " dollars!" << std::endl << std::endl;
	return mPrice;
}
