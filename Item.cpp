#include "Item.h"

// Constructors
Item::Item(int n, double p) : price(p), numItems(n) {}

// Getters
double Item::get_Price() { return price; }

int Item::get_numItems() { return numItems; }

// Setters
void Item::set_numItems(int n) { numItems = n; }

// Methods
void Item::changeAmount(int n) { numItems += n; }
