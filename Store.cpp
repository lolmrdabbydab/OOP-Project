#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"

using namespace std;

// Constructors
Store::Store() : StoreBase() {} 

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

void Store::updateStore()
{
    for (auto i = this->get_inventory().begin();i!= this->get_inventory().end();i++){
        if(i->second->get_isPerishableItem()){
            i->second-> updateItem();
        }   
    }
}

// Methods
void Store::print() {}

// Destructor
Store::~Store() {}