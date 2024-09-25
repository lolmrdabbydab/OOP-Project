#ifndef MEAT_H
#define MEAT_H

#include <iostream>

#include "Item.h"

class Meat : public Item
{
private:
public:
    // Constructors
    Meat(int n, double p);
    
    // Methods
    void print();
};

#endif