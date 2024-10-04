#ifndef MILK_H
#define MILK_H

#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Milk : public PerishableItem
{
public:
    string milkSource;
    string milkType;

private:
    // Constructors
    Milk(int, double, string, int, int*, string, string);
    Milk();
    
    // Getters
    string get_milkSource();
    string get_milkType();
    
    // Setters
    void set_milkSource(string);
    void set_milkType(string);

    // Methods
    void print() override;

    // Destructors
    ~Milk();
};

#endif
