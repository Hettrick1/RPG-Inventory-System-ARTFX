#include "FoodProcessor.h"

FoodProcessor::FoodProcessor()
{
}

FoodProcessor::~FoodProcessor()
{
}

Item* FoodProcessor::CookItem()
{
    if (mPot.size() == 1) {
        switch (mPot[0]->GetType())
        {
        case ItemType::Stone:
            Material* mat = new Material(ItemType::Stone, 0, 100, "Gravel");
            return mat;
        case ItemType::Wood:
            Material* mat = new Material(ItemType::Wood, 0, 150, "Planks");
            return mat;
        default:
            std::cout << "Sorry, you can't craft anything with this !" << std::endl << "Try to add more things !" << std::endl;
            break;
        }
    }
    else if (mPot.size() == 2) { // logique de recettes
        if (mActualRecipie == (FoodType::Herb + FoodType::Vegetable)) { 
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs");
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Mushroom)) {
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Meat)) { 
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0; 
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Herb + FoodType::Water)) {
            
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Mushroom)) {
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Meat)) {
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat; 
        }
        else if (mActualRecipie == (FoodType::Vegetable + FoodType::Water)) {

        }
        else if (mActualRecipie == (FoodType::Mushroom + FoodType::Meat)) {
            Material* mat = new Material(ItemType::Food + ItemType::Cooked + ItemType::Common, mActualRecipie, 500, "Vegetables with herbs"); 
            mActualRecipie = 0;
            return mat;
        }
        else if (mActualRecipie == (FoodType::Mushroom + FoodType::Water)) {

        }
        else {

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
            mPot.push_back(itemToAdd);
            mCanAddToPot = false;
            break;
        case ItemType::Wood:
            mPot.push_back(itemToAdd);
            mCanAddToPot = false;
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
