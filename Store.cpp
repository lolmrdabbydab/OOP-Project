#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

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
    cout << "**********************************************************************************" << endl;
    cout << setw(50) << right << "Store's Inventory" << endl;
    cout << "**********************************************************************************" << endl;
    cout << setw(3) << right << " No. " 
         << setw(22) << right << "Product Name" << setw(14) << right << "|" 
         << setw(14) << right << "Inventory  |" 
         << setw(20) << right << "Retail Price" << endl;
    cout << "**********************************************************************************" << endl;

    for (size_t i = 0; i < this->get_numDifferentItem(); i++)
    {
        // Product details with columns for Product Name, Inventory, and Retail Price separated by "|"
        cout << setw(3) << right << i + 1 << ". ";
        cout << setw(35) << left << itemNames[i] << "| ";
        cout << "x" << setw(10) << left << this->get_inventory()[itemNames[i]]->get_numItem() << " | ";
        cout << "$" << setw(10) << left << this->get_inventory()[itemNames[i]]->get_price() << endl;
    }

    cout << "**********************************************************************************" << endl;
    cout << "  Current Balance: $" << balance << endl;
    cout << "  Balance Target: $" << target << endl;
    cout << "----------------------------\n" << endl;
}

// Destructor
Store::~Store() {}