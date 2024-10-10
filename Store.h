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
    int currentDay=1;
    int numCustomer=1;
    double balance=30;
    double rating=5;
    double target=10;

public:
    // Constructors
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
    void updateStore();
    void print() override;

    // Destructor
    ~Store() ;
};

#endif