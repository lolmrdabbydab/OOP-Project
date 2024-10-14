#ifndef STOREBASE_H
#define STOREBASE_H

#include <iostream>
#include <map>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"
#include "Meat.h"
#include "Milk.h"
#include "Toy.h"
#include "Soap.h"

using namespace std;

class StoreBase : public Printable
{
private:
    int numDifferentItem;
    map<string, Item*> inventory;

protected:
    string itemNames[10] =
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
            "Dove Body Wash"
        };

public:
    // Constructor
    StoreBase();

    // Getters
    int get_numDifferentItem();
    map<string, Item*> get_inventory();
    string* get_itemNames();

    // Setters
    void set_numDifferentItem(int n);
    void set_inventory(map<string, Item*>);
    
    // Methods
    void change_numDifferentItem(int n); // Takes positive/negative value to adjust numDifferentItem variable ≠ Not setter
    virtual void print();

    // Destructor
    ~StoreBase();
};

#endif