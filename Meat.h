#ifndef MEAT_H
#define MEAT_H

#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Meat : public PerishableItem
{
public:
    string fromAnimal;
    string bodyPart;

private:
    // Constructors
    Meat(string, string);
    Meat();
    
    // Getters
    string get_fromAnimal();
    string get_bodyPart();

    // Setters
    void set_fromAnimal(string);
    void set_bodyPart(string);

    // Methods
    void print() override;

    // Destructor
    ~Meat();
};

#endif