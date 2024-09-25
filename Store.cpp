#include <iostream>

#include "Store.h"

// Constructors
Store::Store(int currentDay, double b, double r, int c, double t, int i0, int i1, int i2, int i3, int i4, int i5) : StoreBase(i0, i1, i2, i3, i4, i5), currentDay(currentDay), balance(b), rating(r), numOfcus(c), target(t) {}
Store::Store() : Store(1, 30.0, 5.0, 1, 10, 0, 0, 0, 0, 0, 0) {}

// Getters
double Store::getBalance() { return balance; }

double Store::getRating() { return rating; }

int Store::getDay() { return currentDay; }

double Store::getTarget() { return target; }

int Store::getNumCus() { return numOfcus; }

// Setters
void Store::setBalance(double b) { balance = b; }

void Store::setRating(double r) { rating = r; }

// Methods
void Store::print() {}

// Destructors
Store::~Store() {}