#ifndef EGG_H
#define EGG_H

#include <iostream>

#include "Item.h"
class Egg : public Item
{
private:
    bool isCaged;

public:
    // Constructors
    Egg(int n, bool isCaged, double p);
    
    // Methods
    void print();
};

#endif