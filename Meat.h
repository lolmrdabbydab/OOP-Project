#ifndef MEAT_H
#define MEAT_H

#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Meat : public PerishableItem
{
private:
    bool fromAnimal;
    string bodyPart;

public:
    // Constructors
    Meat(int numItem, double price, string brand, int shelfLifeInDay, bool isPerishableItem, bool fromAnimal, string bodyPart);
    // Getters
    bool get_fromAnimal() const;
    string get_bodyPart() const;

    // Setters
    void set_fromAnimal(bool a);
    void set_bodyPart(string);

    // Methods
    void print() override;

    // Destructor
    ~Meat();
};

#endif