#ifndef SUPPLIANT_H
#define SUPPLIANT_H

#include <iostream>
#include "StoreBase.h"
class Suppliant:public StoreBase{
    private:
        double costs[6];
        double currentCosts[6];
    public:
        Suppliant();
        void updateCost();
        void print();
        double* getCurrentCost();
        ~Suppliant();
};
#endif