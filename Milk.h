#ifndef MILK_H
#define MILK_H

#include <iostream>

#include "Item.h"

class Milk : public Item
{
private:
    std::string milkType;

public:
    // Constructors
    Milk(int n, std::string t, double p);
    
    // Methods
    void print();
};

#endif