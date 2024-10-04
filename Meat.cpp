#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Meat.h"

using namespace std;

// Constructors
Meat::Meat(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string fromAnimal, string bodyPart)
    : PerishableItem(numItem, price, brand, shelfLifeInDay, expirationList), fromAnimal(fromAnimal), bodyPart(bodyPart) {}
Meat::Meat() : Meat(0, 0.0, "NaN", 0, vector<int>, "NaN", "NaN") {}

// Getters
string Meat::get_fromAnimal() const { return fromAnimal; }
string Meat::get_bodyPart() const { return bodyPart; }

// Setters
void Meat::set_fromAnimal(string fromAnimal) { this->fromAnimal = fromAnimal; }
void Meat::set_bodyPart(string bodyPart) { this->bodyPart = bodyPart; }

// Methods
void Meat::print() {}

// Destructors
Meat::~Meat() {}