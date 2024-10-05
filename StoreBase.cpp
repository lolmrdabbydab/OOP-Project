#include "StoreBase.h"
StoreBase::StoreBase()
{
    this->numDifferentItem =10;
    Item* item1 = new Egg(0,5.5,"",7,true,true,"Hens");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item2 = new Egg(0,6,"",7,true,true,"Duck");
    std::pair<string,Item*> i2 = {itemNames[1],item2};
    this->inventory.insert(i2);

    Item* item3 = new Milk(0,5,"",true,5,"Cow","non-vegan");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item4 = new Milk(0,5,"",5,"Almond","vegan");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item5 = new Meat(0,8.6,"",3,true,"Chicken","Wing");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item6 = new Meat(0,13,"",3,true,"Beef","Sirloin");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item7 = new Toy(0,7.7,"PlayDough",false,"Sand",3);
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item8 = new Toy(0,7.7,"Lego",false,"Figure",2);
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item9 = new Soap(0,12,"Dove",false,"Shampoo");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);

    Item* item10 = new Shoap(0,13,"Dove",false,"Body Wash");
    std::pair<string,Item*> i1 = {itemNames[0],item1};
    this->inventory.insert(i1);
}
int StoreBase::get_numDifferentItem()
{
    return this->numDifferentItem;
}
std::map<std::string, Item *> StoreBase::get_inventory()
{
    return this->inventory;
}
void StoreBase::set_numDifferentItem(int n)
{
    this->numDifferentItem = n;
}
void StoreBase::set_inventory(std::map<std::string, Item *>)
{
}

void StoreBase::change_numDifferentItem(int n)
{
    this->numDifferentItem+=n;
}


std::string *StoreBase::get_itemNames()
{
    return itemNames;
}

void StoreBase::print()
{
}

StoreBase::~StoreBase()
{
}
