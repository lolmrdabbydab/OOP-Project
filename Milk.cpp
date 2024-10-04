#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Milk.h"

using namespace std;

// Constructors
Milk::Milk(string milkSource, string milkType), PerishableItem(shelfLifeinDay, expiration), milkSource(milkSource), milkType(milkType) {}
Milk::Milk() : Milk("NaN", "NaN") {}

// Getters
string Milk::get_milkSource() { return milkSource; }
string Milk::get_milkType() { return milkType; }

// Setters
void Milk::set_milkSource(string milkSource) { this->milkSource = milkSource; }
void Milk::set_milkType(string milkType) { this->milkType = milkType; }

// Methods
void Milk::print() { return; }

// Destructors
Milk::~Milk() { return; }