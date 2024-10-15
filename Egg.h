#ifndef EGG_H
#define EGG_H

#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Egg : public PerishableItem
{
private:
    bool fromAnimal;
    string eggType;

public:
    // Constructors
    Egg(int numItem, double price, string brand, int shelfLifeInDay, bool fromAnimal, bool isPerishableItem, string eggType);

    // Getters
    bool get_fromAnimal() const;
    string get_eggType() const;

    // Setters
    void set_fromAnimal(bool);
    void set_eggType(string);

    // Methods
    void print() override;

    // Destructors
    ~Egg();
};

#endif