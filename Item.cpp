#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"

using namespace std;

// Constructors
Item::Item(int numItem, double price, string brand) : numItem(numItem), price(price), brand(brand) {}
Item::Item() : Item(0, 0, "NaN") {}

// Getters
int Item::get_numItem() { return numItem; }
double Item::get_price() { return price; }
string Item::get_brand() { return brand; }

// Setters
void Item::set_numItem(int numItem) { this->numItem = numItem; }
void Item::set_price(double price) { this->price = price; }
void Item::set_brand(string brand) { this->brand = brand; }

// Methods
void Item::print() { return; }

// Destructor
Item::~Item() {}