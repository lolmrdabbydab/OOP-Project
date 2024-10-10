#ifndef STOREBASE_H
#define STOREBASE_H

#include <iostream>
#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"
#include "Meat.h"
#include "Milk.h"
#include "Toy.h"
#include "Soap.h"
#include <map>

class StoreBase : public Printable
{
private:
    int numDifferentItem;
    std::map<std::string, Item *> inventory;

protected:
    std::string itemNames[10] =
        {
            "Dozen of Free Range Hens Egg",
            "Dozen of Cage Free Duck Egg",
            "Bottle of Cow Milk",
            "Bottle of Almond Milk",
            "Chicken Wings (1kg)",
            "Cow Sirloin (1kg)",
            "PlayDough Sand",
            "Lego Figure",
            "Dove Shampoo",
            "Dove Body Wash"};

public:
    StoreBase();
    int get_numDifferentItem();
    std::map<std::string, Item *> get_inventory();

    void set_numDifferentItem(int n);
    void set_inventory(std::map<std::string, Item *>);
    void change_numDifferentItem(int n);
    std::string *get_itemNames();
    virtual void print();

    ~StoreBase();
};

#endif