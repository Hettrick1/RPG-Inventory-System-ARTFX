#include "FoodProcessor.h"

FoodProcessor::FoodProcessor()
{
}

FoodProcessor::~FoodProcessor()
{
}

Item* FoodProcessor::CookItem()
{
    for (int i = 0; i < mPot.size(); i++) {
        switch (mPot[i]->GetType())
        {
        case ItemType::Food :
            break;
        case ItemType::Water:
            break;
        case ItemType::Stone:
            Material* mat = new Material(ItemType::Stone, 0, 100, "Gravel");
            return mat;
        case ItemType::Wood:
            break;
        }
    }
    return nullptr;
}
