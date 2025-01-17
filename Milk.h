#ifndef MILK_H
#define MILK_H

#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Milk : public PerishableItem
{
private:
    string milkSource;
    string milkType;

public:
    // Constructors
    Milk(int numItem, double price, string brand, bool isPerishableItem, int shelfLifeInDay, string milkSource, string milkType);

    // Getters
    string get_milkSource() const;
    string get_milkType() const;

    // Setters
    void set_milkSource(string);
    void set_milkType(string);

    // Methods
    void print() override;

    // Destructor
    ~Milk();
};

#endif