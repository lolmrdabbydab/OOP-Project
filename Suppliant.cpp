#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"
#include "Suppliant.h"

using namespace std;

// Constructors
Suppliant::Suppliant(int numDifferentItem, map<string, Item*> inventory, vector<double> costRefList, vector<double> costList) : StoreBase(numDifferentItem, inventory), costRefList(costRefList), costList(costList) {}
//Suppliant::Suppliant() : Suppliant(vector<double>(), vector<double>()) {}
    /*
    -= Default Suppliant Inventory =-
    Egg (1): Free Range Hens Egg
    Egg (2): Cage Free Duck Egg
    Milk (1): Cow Full Fat
    Milk (1): Almond Vegan
    Meat (1): Chicken Wing
    Meat (2): Cow Sirloin
    Toy (1): PlayDough Sand (1 year old)
    Toy (2): Lego Figure (3 year old)
    Soap (1): Dove Shampoo
    Soap (2): Dove Body Wash
    */


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