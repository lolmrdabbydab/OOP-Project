#ifndef SUPPLIANT_H
#define SUPPLIANT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Printable.h"
#include "StoreBase.h"

using namespace std;

class Suppliant : public StoreBase
{
private:
    double costRefList[10];
    double costList[10];

public:
    // Constructors
    Suppliant();

    // Getters
    double* get_costRefList();
    double* get_costList();

    // Setters
    void set_costRefList(double[10]);
    void set_costList(double[10]);

    // Methods
    void print() override;
    void updateCost();
    
    // Destructor
    ~Suppliant();
};

#endif