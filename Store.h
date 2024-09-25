#ifndef STORE_H
#define STORE_H

#include <iostream>

#include "StoreBase.h"
#include "Item.h"
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
    Store();
    Store(int currentDay, double b, double r, int c, double t, int i0, int i1, int i2, int i3, int i4, int i5);
    
    // Getters
    int get_day();
    int get_numCustomer();
    double get_balance();
    double get_rating();
    double get_target();
    
    // Setters
    void set_balance(double b);
    void set_rating(double r);
    
    // Methods
    void print();

    // Destructors
    ~Store();
};

#endif