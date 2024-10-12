#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "Item.h"

using namespace std;

// Constructors
Item::Item(int numItem, double price, string brand,bool isPerishableItem) : numItem(numItem), price(price), brand(brand),isPerishableItem(isPerishableItem) {}
Item::Item() : Item(0, 0, "NaN",false) {}

// Getters
int Item::get_numItem() const { return numItem; }
double Item::get_price() const { return price; }
string Item::get_brand() const { return brand; }
bool Item::get_isPerishableItem() const { return this->isPerishableItem; }

int Item::get_shelfLifeInDay() { return 0; }
int *Item::get_expirationList() { return nullptr; }

// Setters
void Item::set_numItem(int numItem) { this->numItem = numItem; }
void Item::set_price(double price) { this->price = price; }
void Item::set_brand(string brand) { this->brand = brand; }
void Item::set_isPerishableItem(bool isPerishableItem) { this->isPerishableItem = isPerishableItem; }

void Item::set_expirationList(int *expirationList) {}

// Methods
void Item::print() {}

void Item::sellItem(int amount) { return; }
void Item::updateItem() {}
void Item::change_numItem(int numItem) { this->numItem += numItem; }

// Destructor
Item::~Item() {}