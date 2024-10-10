#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"

using namespace std;

// Constructors
Egg::Egg(int numItem, double price, string brand, int shelfLifeInDay, bool fromAnimal, bool isPerishable, string eggType)
    : PerishableItem(numItem, price, brand, isPerishable, shelfLifeInDay), fromAnimal(fromAnimal), eggType(eggType) {}

// Getters
bool Egg::get_fromAnimal() const { return fromAnimal; }
string Egg::get_eggType() const { return eggType; }

// Setters
void Egg::set_fromAnimal(bool fromAnimal) { this->fromAnimal = fromAnimal; }
void Egg::set_eggType(string eggType) { this->eggType = eggType; }

// Methods
void Egg::print() {}

// Destructors
Egg::~Egg() {}