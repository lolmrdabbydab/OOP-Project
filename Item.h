#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"

using namespace std;

class Item : public Printable
{
protected:
    int numItem;
    double price;
    string brand;

public:
    // Constructors
    Item();
    Item(int, double, string);

    // Getters
    int get_numItem();
    double get_price();
    string get_brand();

    // Setters
    void set_numItem(int);
    void set_price(double);
    void set_brand(string);

    // Methods
    void print() override;

    // Destructor
    virtual ~Item();
}

#endif