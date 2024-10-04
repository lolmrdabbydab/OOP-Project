#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Meat.h"

using namespace std;

// Constructors
Meat::Meat(string fromAnimal, string bodyPart) : PerishableItem(shelfLifeinDay, expirationList), fromAnimal(fromAnimal), bodyPart(bodyPart) {}
Meat::Meat() : Meat("NaN", "NaN") {}

// Getters
string Meat::get_fromAnimal() { return fromAnimal; }
string Meat::get_bodyPart() { return bodyPart; }

// Setters
void Meat::set_fromAnimal(string fromAnimal) { this->fromAnimal = fromAnimal; }
void Meat::set_bodyPart(string bodyPart) { this->bodyPart = bodyPart; }

// Methods
void Meat::print() { return; }

// Destructors
Meat::~Meat() { return; }