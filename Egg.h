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
    Egg(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string fromAnimal, string eggType);
    Egg();

    // Getters
    string get_fromAnimal() const;
    string get_eggType() const;
    
    // Setters
    void set_fromAnimal(string);
    void set_eggType(string);
    
    // Methods
    void print() override;
    
    // Destructors
    ~Egg() override;
};
#endif