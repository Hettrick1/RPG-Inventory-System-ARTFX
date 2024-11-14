#include "Item.h"

Item::Item(std::uint8_t t, int p, std::string n)
{
    mType = t;
    mPrice = p;
    mName = n;
}

Item::~Item()
{
}

std::uint8_t Item::GetType()
{
    return mType;
}

std::string Item::GetName()
{
    return mName;
}

// I added this function too late so that's why in my foodProcessor class I'm not using it
bool Item::HasTag(std::uint8_t tag)
{
    return (mType & tag) != 0;
}
