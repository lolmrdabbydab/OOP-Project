#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"

using namespace std;

// Constructors
Egg::Egg(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string fromAnimal, string eggType) 
    : PerishableItem(numItem, price, brand, shelfLifeInDay, expirationList), fromAnimal(fromAnimal), eggType(eggType) {}
Egg::Egg() : Egg(0, 0.0, "NaN", 0, vector<int>, "NaN", "NaN") {}

// Getters
string Egg::get_fromAnimal() const { return fromAnimal; }
string Egg::get_eggType() const { return eggType; }

// Setters
void Egg::set_fromAnimal(string fromAnimal) { this->fromAnimal = fromAnimal; }
void Egg::set_eggType(string eggType) { this->eggType = eggType; }

// Methods
void Egg::print() {}

// Destructors
Egg::~Egg() {}