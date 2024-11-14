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
    Potion* pot2 = new Potion(ItemType::Food, 500, "with2", PotionType::FireResistance);
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
}

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
        std::cout << i << ". " << mInventory[i]->GetName() << " - " << (int)mInventory[i]->GetType() << std::endl;
    }
}
