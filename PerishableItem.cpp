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
void PerishableItem::set_expirationList(int *expirationListTemp)
{
    for (int i = 0; i < this->shelfLifeInDay; i++)
    {
        expirationList[i] = expirationListTemp[i];
    }
    return;
}

// Methods
void PerishableItem::print() { return void(); }

void PerishableItem::sellItem(int n)
{

    for (int i = 0; i < shelfLifeInDay; i++) // Loop through avaliable stock
    {
        if (n == 0) 
        {
            return;
        }
        if (n > expirationList[i]) // If amount to sell exceed stock with "i" days left till expire, sell all stock with that expiry date
        {
            n -= expirationList[i]; // Reduce item to sell with avaliable stock for that expiry date
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
    for (int i = 0; i < shelfLifeInDay-1; i++)
    {
        expirationList[i] = expirationList[i + 1];
        count += expirationList[i];
    }
    expirationList[shelfLifeInDay - 1] = 0;
    this->numItem = count;
}

// Destructors
PerishableItem::~PerishableItem() { delete[] this->expirationList; }