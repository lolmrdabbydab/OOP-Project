#include <iostream>

#include "Store.h"

// Constructors
Store::Store(int currentDay, double b, double r, int c, double t, int i0, int i1, int i2, int i3, int i4, int i5) : StoreBase(i0, i1, i2, i3, i4, i5), currentDay(currentDay), balance(b), rating(r), numCustomer(c), target(t) {}
Store::Store() : Store(1, 30.0, 5.0, 1, 10, 0, 0, 0, 0, 0, 0) {}

// Getters
double Store::get_balance() { return balance; }

double Store::get_rating() { return rating; }

int Store::get_day() { return currentDay; }

double Store::get_target() { return target; }

int Store::get_numCustomer() { return numCustomer; }

// Setters
void Store::set_balance(double b) { balance = b; }

void Store::set_rating(double r) { rating = r; }

// Methods
void Store::print() {}

// Destructors
Store::~Store() {}