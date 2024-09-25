#ifndef SUPPLIANT_H
#define SUPPLIANT_H

#include <iostream>

#include "StoreBase.h"
class Suppliant : public StoreBase
{
private:
    double costs[6];
    double currentCosts[6];

public:
    // Constructors
    Suppliant();

    // Getters
    double *getCurrentCost();

    // Methods
    void updateCost();
    void print();

    // Destructors
    ~Suppliant();
};

#endif