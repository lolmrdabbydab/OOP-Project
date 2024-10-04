#include "StoreBase.h"
StoreBase::StoreBase()
{
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

void StoreBase::addItem(std::pair<std::string, Item *>)
{
}

void StoreBase::removeItem(std::string)
{
}

void StoreBase::print()
{
}

StoreBase::~StoreBase()
{
}
