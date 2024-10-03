#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"
#include "StoreBase.h"
#include "Suppliant.h"

using namespace std;

// Constructors
Suppliant::Suppliant(vector<double> costRefList, vector<double> costList) : costRefList(costRefList), costList(costList) {}
//Suppliant::Suppliant() : Suppliant(vector<double>(), vector<double>()) {}

// Getters
vector<double> Suppliant::get_costRefList() { return costRefList; }
vector<double> Suppliant::get_costList() { return costList; }

// Setters
void Suppliant::set_costRefList(vector<double> costRefList) { this->costRefList = costRefList; }

void Suppliant::set_costList(vector<double> costList) { this->costList = costList; }

// Methods
void Suppliant::print() { return; }

// Destructor
Suppliant::~Suppliant() {}