#include <iostream>
#include "Store.h"

Store::Store(): Store(1,30,5.0,0,0,0,0,0,0,0)
{
    
}

Store::Store(int currentDay, double b, double r, int i0, int i1, int i2, int i3, int i4, int i5):StoreBase(i0,i1,i2,i3,i4,i5)
{
    currentDay = currentDay;
    balance = b;
    rating =r;
}

double Store::getBalance()
{
    return balance;
}

void Store::setBalance(double b)
{
    balance = b;
}

double Store::getRating()
{
return rating;
}

void Store::setRating(double r)
{
    rating = r;
}

void Store::print()
{
    
}