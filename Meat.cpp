#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"

using namespace std;

// Constructors
Meat::Meat(string, string) : PerishableItem(shelfLifeinDay, expirationList), fromAnimal(fromAnimal), bodyPart(bodyAnimal) {}
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