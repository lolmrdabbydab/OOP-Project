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
    Store(int, map<string, Item*>, int, int, double, double, double);
    Store();

    // Getters
    int get_currentDay();
    int get_numCustomer();
    double get_balance();
    double get_rating();
    double get_target();

    // Setters
    void set_currentDay(int);
    void set_numCustomer(int);
    void set_balance(double);
    void set_rating(double);
    void set_target(double);

    // Methods
    void print() override;

    // Destructor
    ~Store();
};

#endif