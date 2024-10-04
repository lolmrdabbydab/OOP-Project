#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"

using namespace std;

class Store : public StoreBase
{
private:
    int currentDay;
    int numCustomer;
    double balance;
    double rating;
    double target;

public:
    // Constructors
    Store(int numDifferentItem, map<string, Item*> inventory, int currentDay, int numCustomer, double balance, double rating, double target);
    Store();

    // Getters
    int get_currentDay() const;
    int get_numCustomer() const;
    double get_balance() const;
    double get_rating() const;
    double get_target() const;

    // Setters
    void set_currentDay(int);
    void set_numCustomer(int);
    void set_balance(double);
    void set_rating(double);
    void set_target(double);

    // Methods
    void print() override;

    // Destructor
    ~Store() override;
};

#endif