#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"
#include "Item.h"

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
    currentDay += 1;
    target += currentDay + 5 * (currentDay / 5);
    numCustomer += currentDay / 5; // numCustomer increase by 1 every 5 days

    map<string, Item *> _inventory = this->get_inventory();
    for (auto i = _inventory.begin(); i != _inventory.end(); i++)
    {
        if (i->second->get_isPerishableItem())
        {
            i->second->updateItem();
        }
    }
}

// Methods
void Store::print()
{
    cout << "************************************" << endl;
    cout << "\t Store's Inventory" << endl;
    cout << "************************************\n" << endl;
    for (int i = 0; i < StoreBase::get_numDifferentItem(); i++)
    {
        cout << i + 1 << ". " << itemNames[i] << ": x" << get_inventory()[itemNames[i]]->get_numItem() << endl;
    }
    cout << "\n************************************\n" << endl;
}

// Destructor
Store::~Store() {}