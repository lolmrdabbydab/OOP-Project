#include <iostream>
#include "Item.h"
#include "PerishableItem.h"

// Constructor
PerishableItem::PerishableItem(int numItem, double price, std::string brand, bool isPerishableItem, int shelfLifeInDay) : Item(numItem, price, brand, isPerishableItem), shelfLifeInDay(shelfLifeInDay)
{
    this->expirationList = new int[shelfLifeInDay]();
}

// Getters
int PerishableItem::get_shelfLifeInDay() { return shelfLifeInDay; }
int *PerishableItem::get_expirationList() { return expirationList; }

// Setters
void PerishableItem::set_shelfLifeInDay(int n) { shelfLifeInDay = n; }
void PerishableItem::set_expirationList(int* nList)
{
    for (int i = 0; i < this->shelfLifeInDay; i++)
    {
        expirationList[i] = nList[i];
    }
    return;
}

// Methods
void PerishableItem::print() { return void(); }

void PerishableItem::sellItem(int n)
{
    for (int i = 0; i < shelfLifeInDay; i++)
    {
        if (n == 0)
        {
            break;
        }
        if (n > expirationList[i])
        {
            n -= expirationList[i];
            expirationList[i] = 0;
        }
        else
        {
            expirationList[i] -= n;
            n = 0;
        }
    }
}

void PerishableItem::updateItem()
{
    int count = 0;
    expirationList[shelfLifeInDay - 1] = 0;
    for (int i = 1; i < shelfLifeInDay; i++)
    {
        expirationList[i] = expirationList[i + 1];
        count += expirationList[i];
    }
    this->numItem = count;
}

// Destructors
PerishableItem::~PerishableItem() { delete[] this->expirationList; }