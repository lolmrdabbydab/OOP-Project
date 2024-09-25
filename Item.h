#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "Printable.h"
class Item : public Printable
{
private:
    int numberOfItems;
    double price;

public:
    // Constructors
    Item(int n, double p);
    
    // Getters
    double getPrice();
    int getNumberOfItems();

    // Setters
    void setNumberOfItems(int n);

    // Methods
    void changeAmount(int n);
};

#endif