#include "Toy.h"
#include <string>
using namespace std;

// Constructors
Toy::Toy(string, string), Item(NumItem, price, brand), toyType(toyType), minAgeRestriction(minAgeRestriction) {};
Toy::Toy()

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
