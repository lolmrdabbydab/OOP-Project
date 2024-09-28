#ifndef STOREBASE_H
#define STOREBASE_H

#include <iostream>

#include "Printable.h"
#include "Item.h"

class StoreBase : public Printable
{
private:
    int numDifferentItem = 6;
    Item **items = new Item *[6];

protected:
    std::string nameItems[6] = {"12 Caged Eggs", "12 Free Range Eggs", "A bottle of Cow Milk", "A bottle of plant-based milk", "Beef", "Chicken"};

public:
    // Constructors
    StoreBase();
    StoreBase(int i0, int i1, int i2, int i3, int i4, int i5);

    // Getters
    Item **get_Items();
    std::string *get_NameItems();

    // Methods
    virtual void print();

    // Destructors
    ~StoreBase();
};

#endif