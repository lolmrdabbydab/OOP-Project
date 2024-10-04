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
    string fromAnimal;
    string bodyPart;

public:
    // Constructors
    Meat(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string fromAnimal, string bodyPart);
    Meat();

    // Getters
    string get_fromAnimal() const;
    string get_bodyPart() const;

    // Setters
    void set_fromAnimal(string);
    void set_bodyPart(string);

    // Methods
    void print() override;

    // Destructor
    ~Meat() override;
};

#endif