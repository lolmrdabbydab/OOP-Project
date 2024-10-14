#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Meat.h"

using namespace std;

// Constructors
Meat::Meat(int numItem, double price, string brand, int shelfLifeInDay, bool isPerishableItem, bool fromAnimal, string bodyPart): PerishableItem(numItem, price, brand,isPerishableItem, shelfLifeInDay),fromAnimal(fromAnimal),bodyPart(bodyPart) {}

// Getters
bool Meat::get_fromAnimal() const { return fromAnimal; }
string Meat::get_bodyPart() const { return bodyPart; }

// Setters
void Meat::set_fromAnimal(bool fromAnimal) { this->fromAnimal = fromAnimal; }
void Meat::set_bodyPart(string bodyPart) { this->bodyPart = bodyPart; }

// Methods
void Meat::print() {}

// Destructors
Meat::~Meat() {}