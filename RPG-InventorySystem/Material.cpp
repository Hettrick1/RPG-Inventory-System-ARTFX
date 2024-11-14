#include "Material.h"

Material::Material(std::uint8_t itemType, std::uint8_t foodType, int price, std::string name) : Item(itemType, price, name)
{
	mFoodType = foodType;
}

Material::~Material()
{
}

uint8_t Material::GetFoodType()
{
	return mFoodType;
}

void Material::Burn()
{
}

int Material::Sell()
{
	std::cout << std::endl << "You just sold a material for : " << mPrice << " dollars!" << std::endl << std::endl;
	return mPrice;
}

bool Material::canCraft()
{
	return true;
}



