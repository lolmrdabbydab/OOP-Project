#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Milk.h"

using namespace std;

// Constructors
Milk::Milk(int numItem, double price, string brand, bool isPerishableItem, int shelfLifeInDay, string milkSource, string milkType):PerishableItem(numItem,price,brand,isPerishableItem,shelfLifeInDay),milkSource(milkSource),milkType(milkType)
{
}


// Getters
string Milk::get_milkSource() const { return milkSource; }
string Milk::get_milkType() const { return milkType; }

// Setters
void Milk::set_milkSource(string milkSource) { this->milkSource = milkSource; }
void Milk::set_milkType(string milkType) { this->milkType = milkType; }

// Methods
void Milk::print() {}

// Destructors
Milk::~Milk() {}