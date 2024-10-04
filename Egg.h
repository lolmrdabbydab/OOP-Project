#ifndef EGG_H
#define EGG_H

#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

class Egg : public PerishableItem
{
public:
    string fromAnimal;
    string eggType;

private:
    // Constructors
    Egg(string, string);
    Egg();

    // Getters
    string get_fromAnimal();
    string get_eggType();
    
    // Setters
    void set_fromAnimal(string);
    void set_eggType(string);
    
    // Methods
    void print() override;
    
    // Destructors
    ~Egg();
};
#endif