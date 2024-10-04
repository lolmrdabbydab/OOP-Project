#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"
#include "Soap.h"

using namespace std;

// Constructors
Soap::Soap(string), Item(numItem, price, brand), soapType(soapType) {};
Soap:Soap() : Soap("NaN") {}

// Getters
string Soap::get_soapType() { return soapType; }

// Setters
void Soap::set_soapType(string soapType) { this->soapType = soapType; }

// Methods
void Soap::print() { return; }

// Destructor
Soap::~Soap() { return; }