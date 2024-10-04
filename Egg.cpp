#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"

using namespace std;

// Constructors
Egg::Egg(string fromAnimal, string eggType) : Perishable(shelfLifeinDay, expiration), fromAnimal(fromAnimal), eggType(eggType) {}
Egg:Egg() : Egg("NaN", "NaN") {}

// Getters
string Egg::get_fromAnimal() { return fromAnimal; }
string Egg::get_eggType() { return eggType; }

// Setters
void Egg::set_fromAnimal(string fromAnimal) { this-> fromAnimal = fromAnimal; }
void Egg::set_eggType(string eggType) { this->eggType = eggType; }

// Methods
void Egg::print() { return; }

// Destructors
Egg:~Egg() { return; }