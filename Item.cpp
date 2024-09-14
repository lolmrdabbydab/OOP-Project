#include "Item.h"

Item::Item():Item(0,0)
{
}


Item::Item(int n, double p)
{
    price = p;
    numberOfItems = n;
}

int Item::getNumberOfItems()
{
    return 0;
}

void Item::setNumberOfItems(int n)
{
    numberOfItems = n;
}

void Item::changeAmount(int n)
{
    numberOfItems += n;
}
