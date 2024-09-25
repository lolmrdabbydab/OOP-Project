#ifndef STORE_H
#define STORE_H

#include <iostream>

#include "StoreBase.h"
#include "Item.h"
class Store : public StoreBase
{
private:
    int currentDay;
    int numOfcus;
    double balance;
    double rating;
    double target;

public:
    
    // Constructors
    Store();
    Store(int currentDay, double b, double r, int c, double t, int i0, int i1, int i2, int i3, int i4, int i5);
    
    // Getters
    int getDay();
    int getNumCus();
    double getBalance();
    double getRating();
    double getTarget();
    
    // Setters
    void setBalance(double b);
    void setRating(double r);
    
    // Methods
    void print();

    // Destructors
    ~Store();
};

#endif