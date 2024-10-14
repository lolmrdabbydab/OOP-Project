#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "Soap.h"

using namespace std;

// Constructors
Soap::Soap(int numItem, double price, string brand, bool isPerishableItem, string soapType) : Item(numItem, price, brand, isPerishableItem), soapType(soapType)
{
}

// Getters
string Soap::get_soapType() const { return soapType; }

// Setters
void Soap::set_soapType(string soapType) { this->soapType = soapType; }

// Methods
void Soap::print() {}

void Soap::change_numItem(int n) {}

// Destructor
Soap::~Soap() {}