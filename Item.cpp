#include "Item.h"

Item::Item(int n, double p):price(p),numberOfItems(n)
{
}

double Item::getPrice()
{
    return price;
}

int Item::getNumberOfItems()
{
    return numberOfItems;
}

void Item::setNumberOfItems(int n)
{
    numberOfItems = n;
}

void Item::changeAmount(int n)
{
    numberOfItems+=n;
}
