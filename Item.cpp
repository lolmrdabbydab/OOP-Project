#include "Item.h"

// Constructors
Item::Item(int n, double p) : price(p), numberOfItems(n) {}

// Getters
double Item::getPrice() { return price; }

int Item::getNumberOfItems() { return numberOfItems; }

// Setters
void Item::setNumberOfItems(int n) { numberOfItems = n; }

// Methods
void Item::changeAmount(int n) { numberOfItems += n; }
