#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "Toy.h"

using namespace std;

// Constructors
Toy::Toy(int numItem, double price, string brand, string toyType, string minAgeRestriction) : Item(numItem, price, brand), toyType(toyType), minAgeRestriction(minAgeRestriction) {}
Toy::Toy() : Toy(0, 0.0, "NaN", "NaN", "NaN") {}

// Getters
string Toy::get_toyType() { return toyType; }
string Toy::get_minAgeRestriction() { return minAgeRestriction; }

// Setters
void Toy::set_minAgeRestriction(string minAgeRestriction) { this->minAgeRestriction = minAgeRestriction; }
void Toy::set_toyType(string toyType) { this->toyType = toyType; }

// Methods
void Toy::print() { return; };

// Destructor
Toy::~Toy() { return; };