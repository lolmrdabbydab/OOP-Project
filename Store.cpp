#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"

using namespace std;

// Constructors
Store::Store(int numDifferentItem, map<string, Item*> inventory, int currentDay, int numCustomer, double balance, double rating, double target) : StoreBase(numDifferentItem, inventory), currentDay(currentDay), numCustomer(numCustomer), balance(balance), rating(rating), target(target) {}
Store::Store() : Store(10, map<string, Item*>, 1, 1, 30.0, 5, 10) {} // Need to Set Default inventory

// Getters
int Store::get_currentDay() { return currentDay; }
int Store::get_numCustomer() { return numCustomer; }
double Store::get_balance() { return balance; }
double Store::get_rating() { return rating; }
double Store::get_target() { return target; }

// Setters
void Store::set_currentDay(int currentDay) { this->currentDay = currentDay; }
void Store::set_numCustomer(int numCustomer) { this->numCustomer = numCustomer; }
void Store::set_balance(double balance) { this->balance = balance; }
void Store::set_rating(double rating) { this->rating = rating; }
void Store::set_target(double target) { this->target = target; }

// Methods
void Store::print() { return; }

// Destructor
Store::~Store() {}