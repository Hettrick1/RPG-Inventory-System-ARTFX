#include "Material.h"

Material::Material(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

Material::~Material()
{
}
