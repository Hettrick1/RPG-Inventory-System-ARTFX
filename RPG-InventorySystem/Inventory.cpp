#include "Inventory.h"

Inventory::Inventory() // initialize the game
{
    mCraftingTable = new FoodProcessor();
    mMoney = 0;
}

Inventory::~Inventory()
{
}

void Inventory::Init() // for debug purposes
{
    Material* mat = new Material(ItemType::Food + ItemType::Cooked, 0, 500, "Vegetables");
    AddItem(mat);
    Potion* pot2 = new Potion(ItemType::Food + ItemType::Epic, 500, "with2", PotionType::FireResistance);
    AddItem(pot2);
    Material* mat2 = new Material(ItemType::Stone, 0, 500, "Vegetables with herbs");
    AddItem(mat2);
    Material* mat1 = new Material(ItemType::Food + ItemType::Cooked, 0, 500, "Vegetables with ");
    AddItem(mat1);
    Material* mat3 = new Material(ItemType::Wood, 0, 500, "with herbs");
    AddItem(mat3);
    Potion* pot = new Potion(ItemType::Food, 500, "herbs", PotionType::FireResistance);
    AddItem(pot);
    Potion* pot1 = new Potion(ItemType::Food, 500, "with", PotionType::FireResistance);
    AddItem(pot1);
    PrintInventory();
    RemoveItem(0);
    SellItem(0);
    PrintInventory();
    AddItemToPot(4);
    mCraftingTable->PrintPot();
    std::cout << std::endl << GetItem(0)->HasTag(ItemType::Food) << std::endl;
}

// add an item and directly sort regarding the type of the item. 
// If no item with the same tag has been found the item is added at the end
void Inventory::AddItem(Item* item) 
{
    for (auto i = mInventory.end(); i != mInventory.begin(); --i) {
        if ((*std::prev(i))->GetType() == item->GetType()) {
            mInventory.insert(std::next(std::prev(i)), item);
            return;
        }
    }
    mInventory.push_back(item);
}

// remove an item regarding its position
void Inventory::RemoveItem(unsigned int itemIndex)
{
    std::vector<Item*>::iterator i;
    i = mInventory.begin() + itemIndex;
    mInventory.erase(i);
}

// get an item regarding its position in the vector
Item* Inventory::GetItem(unsigned int itemIndex)
{
    std::vector<Item*>::iterator i; 
    i = mInventory.begin() + itemIndex; 
    return *i;
}

// just a simple function to print in the console every items in my inventory 
void Inventory::PrintInventory()
{
    std::cout << "Current Money : " << mMoney << std::endl << std::endl;
    for (int i = 0; i < mInventory.size(); i++) {
        std::cout << i << ". " << mInventory[i]->GetName() << " - " << (int)mInventory[i]->GetType() << std::endl;
    }
}

// this function will call the function sell of an item that will return the sell price and print something in the console
// then it will remove the item from my vector
void Inventory::SellItem(unsigned int itemIndex)
{
    std::vector<Item*>::iterator i;
    i = mInventory.begin() + itemIndex;
    mMoney += (*i)->Sell();
    mInventory.erase(i);
}

// this function will check if the item i want to add to my pot is a backable item 
// then if it craftable it will add it to the pot and removed from my inventory
void Inventory::AddItemToPot(unsigned int itemIndex)
{
    std::vector<Item*>::iterator i;
    i = mInventory.begin() + itemIndex;
    if (dynamic_cast<IBackable*>(*i)) {
        std::cout << std::endl << "This item is backable (craftable)!" << std::endl << std::endl;
        Material* mat = static_cast<Material*>(*i);
        mCraftingTable->AddItemToPot(mat);
        mInventory.erase(i);
    }
    else {
        std::cout << "This item is not backable!" << std::endl << std::endl;
    }
}
