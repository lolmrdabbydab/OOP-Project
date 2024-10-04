#include "PerishableItem.h"

PerisableItem::PerisableItem()
{
}

int PerisableItem::get_shelfLifeInDay()
{
    return shelfLifeInDay;
}

void PerisableItem::set_shelfLifeInDay(int n)
{
    shelfLifeInDay = n;
}

int *PerisableItem::get_expirationList()
{
    return expirationList;
}

void PerisableItem::set_expirationList(int *)
{
    
}

void PerisableItem::print()
{
    return void();
}

PerisableItem::~PerisableItem()
{
}
