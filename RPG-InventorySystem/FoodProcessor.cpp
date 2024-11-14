#include "FoodProcessor.h"

FoodProcessor::FoodProcessor()
{
    mActualRecipie = 0;
    mCanAddToPot = true;
}

FoodProcessor::~FoodProcessor()
{
}

Item* FoodProcessor::CookItem()
{
    Material* mat;
    Potion* pot;
    if (mPot.size() == 1) {
        switch (mPot[0]->GetType())
        {
        case ItemType::Stone:
            mat = new Material(ItemType::Stone, 0, 100, "Gravel");
            return mat;
        case ItemType::Wood:
            mat = new Material(ItemType::Wood, 0, 150, "Planks");
            return mat;
        default:
            std::cout << "Sorry, you can't craft anything with this !" << std::endl << "Try to add different things !" << std::endl;
            break;
        }
    }
    else if (mPot.size() == 2) { // logique de recettes
        if (mActualRecipie == (FoodType::Herb + FoodType::Vegetable)) { 
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 500, "Vegetables with herbs");
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Mushroom)) {
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Meat)) { 
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0; 
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Water)) {
            pot = new Potion(ItemType::Food, 150, "Regen", PotionType::HealthRegen);
            mActualRecipie = 0;
            return pot;
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Mushroom)) {
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 1000, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Meat)) {
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 1000, "Vegetables with herbs");
            mActualRecipie = 0;
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Water)) {
            pot = new Potion(ItemType::Food, 150, "Fire Resistance", PotionType::FireResistance); 
            mActualRecipie = 0;
            return pot;
        }
        else if (mActualRecipie == (FoodType::Mushroom + FoodType::Meat)) {
            mat = new Material(ItemType::Food + ItemType::Cooked, mActualRecipie, 1500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Mushroom + FoodType::Water)) {
            pot = new Potion(ItemType::Food, 150, "Night Vision", PotionType::NightVision); 
            mActualRecipie = 0;
            return pot;
        }
        else {
            mat = new Material(ItemType::Common, 0, 1, "Garbage");
            mActualRecipie = 0;
            return mat; 
        }
    }
    else {
        std::cout << "You need to add materials to the pot if you want to craft someting !" << std::endl;
    }
    return nullptr;
}

void FoodProcessor::AddItemToPot(Material* itemToAdd)
{
    if (mCanAddToPot) {
        switch (itemToAdd->GetType())
        {
        case ItemType::Food:
            mPot.push_back(itemToAdd);
            mActualRecipie += itemToAdd->GetFoodType();
            if (mPot.size() == 2) {          
                mCanAddToPot = false;
            }
            break;
        case ItemType::Stone:
            if (mPot.size() < 1) {
                mPot.push_back(itemToAdd);
                mCanAddToPot = false;
            }
            else {
                std::cout << "You can't this to the pot !" << std::endl;
            }
            break;
        case ItemType::Wood:
            if (mPot.size() < 1) {
                mPot.push_back(itemToAdd);
                mCanAddToPot = false;
            }
            else {
                std::cout << "You can't this to the pot !" << std::endl;
            }
            break;
        default : 
            std::cout << "You can't this to the pot !" << std::endl;
            break;
        }
    }
    else {
        std::cout << "You can't add anything more to the pot !" << std::endl;
    }
}

void FoodProcessor::RemoveElementToPot(int index)
{

}
