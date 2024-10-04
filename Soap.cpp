#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "Soap.h"

using namespace std;

// Constructors
Soap::Soap(int numItem, double price, string brand, string soapType) : Item(numItem, price, brand), soapType(soapType) {}
Soap:Soap() : Soap(0, 0.0, "NaN", "NaN") {}

// Getters
string Soap::get_soapType() const { return soapType; }

// Setters
void Soap::set_soapType(string soapType) { this->soapType = soapType; }

// Methods
void Soap::print() {}

// Destructor
Soap::~Soap() {}