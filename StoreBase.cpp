#include "StoreBase.h"

StoreBase::StoreBase()
{
}

int StoreBase::get_numDifferentItem()
{
    return 0;
}

std::map<std::string, Item *> StoreBase::get_inventory()
{
    return std::map<std::string, Item *>();
}

void StoreBase::set_numDifferentItem()
{
}

void StoreBase::updateItem(std::string itemName, int amount)
{
}

void StoreBase::update_nunumDifferentItem(int n)
{
}

void StoreBase::addItem(std::pair<std::string, Item *>)
{
}

void StoreBase::removeItem()
{
}

void StoreBase::print()
{
}

StoreBase::~StoreBase()
{
}
