#include <iostream>

#include "Item.h"
#include "PerishableItem.h"

using namespace std;

// Constructor
PerishableItem::PerishableItem(int numItem, double price, string brand, bool isPerishableItem, int shelfLifeInDay) : Item(numItem, price, brand, isPerishableItem), shelfLifeInDay(shelfLifeInDay)
{
    this->expirationList = new int[shelfLifeInDay]();
}

// Getters
int PerishableItem::get_shelfLifeInDay() { return shelfLifeInDay; }
int *PerishableItem::get_expirationList() { return expirationList; }

// Setters
void PerishableItem::set_shelfLifeInDay(int shelfLifeInDay) { this->shelfLifeInDay = shelfLifeInDay; }
void PerishableItem::set_expirationList(int *expirationList)
{
    for (int i = 0; i < this->shelfLifeInDay; i++)
    {
        this->expirationList[i] = expirationList[i];
    }
    return;
}

// Methods
void PerishableItem::print() {}
void PerishableItem::sellItem(int amount)
{
    for (int i = 0; i < shelfLifeInDay; i++) // Loop through all available stock across all expiry status
    {
        if (amount == 0) // Input handling -> selling 0 item
        {
            return;
        }
        if (amount > expirationList[i]) // If amount to sell exceed stock with "i" days left till expire, sell all stock with that expiry date
        {
            amount -= expirationList[i]; // Reduce item to sell with available stock for that expiry date
            expirationList[i] = 0;       // Set stock with that expiry date to 0
        }
        else
        {
            expirationList[i] -= amount;
            amount = 0;

            break;
        }
    }

    return;
}

void PerishableItem::updateItem()
{
    int count = 0;
    for (int i = 0; i < shelfLifeInDay - 1; i++)
    {
        expirationList[i] = expirationList[i + 1];
        count += expirationList[i];
    }
    expirationList[shelfLifeInDay - 1] = 0;
    this->numItem = count;
}

// Destructors
PerishableItem::~PerishableItem() { delete[] this->expirationList; }