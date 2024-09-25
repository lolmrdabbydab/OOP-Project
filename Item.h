#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "Printable.h"
class Item : public Printable
{
private:
    int numItems;
    double price;

public:
    // Constructors
    Item(int n, double p);
    
    // Getters
    double get_Price();
    int get_numItems();

    // Setters
    void set_numItems(int n);

    // Methods
    void changeAmount(int n);
};

#endif