#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::Init()
{
    Material* mat = new Material(ItemType::Food + ItemType::Cooked, 0, 500, "Vegetables");
    AddItem(mat);
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
    RemoveItem(3);
}

void Inventory::AddItem(Item* item)
{
    std::vector<Item*>::iterator i;
    for (i = mInventory.end(); i > mInventory.begin(); i--) {
        if ((*i)->GetType() == item->GetType()) {
            i = mInventory.insert(i, item);
        }
        else {
            mInventory.push_back(item);
        }
    }
}

void Inventory::RemoveItem(unsigned int itemIndex)
{
    std::vector<Item*>::iterator i;
    i = mInventory.begin() + itemIndex;
    mInventory.erase(i);
}

Item* Inventory::GetItem(unsigned int itemIndex)
{
    return mInventory[itemIndex];
}

void Inventory::PrintInventory()
{
    for (int i = 0; i < mInventory.size(); i++) {
        std::cout << i << ". " << mInventory[i]->GetName() << " - " << mInventory[i]->GetType() << std::endl;
    }
}
