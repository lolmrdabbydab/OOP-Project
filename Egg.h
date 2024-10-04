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
    string fromAnimal;
    string eggType;

public:
    // Constructors
    Egg(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string fromAnimal, string eggType);
    Egg();

    // Getters
    string get_fromAnimal() const;
    string get_eggType() const;

    // Setters
    void set_fromAnimal(string);
    void set_eggType(string);

    // Methods
    void print() override;

    // Destructors
    ~Egg() override;
};

#endif