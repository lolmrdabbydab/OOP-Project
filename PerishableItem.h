#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include <iostream>
#include "Item.h"
#include "Printable.h"

using namespace std;

class PerishableItem : public Item
{
private:
    int shelfLifeInDay;
    int *expirationList;

public:
    // Constructors
    PerishableItem(int numItem, double price, string brand, bool isPerishable, int shelfLifeInDay);

    // Getters
    int get_shelfLifeInDay();
    int *get_expirationList();

    // Setters
    void set_shelfLifeInDay(int shelfLifeInDay);
    void set_expirationList(int *expirationList);

    // Methods
    virtual void print();
    void sellItem(int amount); // Remove item count from expirationList
    void updateItem();         // Update item count in expirationList and update numItem variable

    // Destructor
    ~PerishableItem();
};
#endif