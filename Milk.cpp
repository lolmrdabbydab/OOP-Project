#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Milk.h"

using namespace std;

// Constructors
Milk::Milk(int numItem, double price, string brand, int shelfLifeInDay, vector<int> expirationList, string milkSource, string milkType) : PerishableItem(numItem, price, brand, shelfLifeInDay, expirationList), milkSource(milkSource), milkType(milkType) {}
Milk::Milk() : Milk(0, 0.0, "NaN", 0, vector<int>, "NaN", "NaN") {}

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