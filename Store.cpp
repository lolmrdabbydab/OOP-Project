#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"

using namespace std;

// Constructors
Store::Store(int numDifferentItem, map<string, Item*> inventory, int currentDay, int numCustomer, double balance, double rating, double target)
    : StoreBase(numDifferentItem, inventory), currentDay(currentDay), numCustomer(numCustomer), balance(balance), rating(rating), target(target) {}

Store::Store() : Store(10, map<string, Item*>(), 1, 1, 30.0, 5, 10) {} // Need to set Default Inventory

// Getters
int Store::get_currentDay() const { return currentDay; }
int Store::get_numCustomer() const { return numCustomer; }
double Store::get_balance() const { return balance; }
double Store::get_rating() const { return rating; }
double Store::get_target() const { return target; }

// Setters
void Store::set_currentDay(int currentDay) { this->currentDay = currentDay; }
void Store::set_numCustomer(int numCustomer) { this->numCustomer = numCustomer; }
void Store::set_balance(double balance) { this->balance = balance; }
void Store::set_rating(double rating) { this->rating = rating; }
void Store::set_target(double target) { this->target = target; }

// Methods
void Store::print() {}

// Destructor
Store::~Store() {}