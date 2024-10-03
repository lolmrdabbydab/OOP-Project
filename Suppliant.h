#ifndef SUPPLIANT_H
#define SUPPLIANT_H

#include <iostream>
#include <string>
#include <vector>

#include "StoreBase.h"
#include "Printable.h"

using namespace std;

class Suppliant : public StoreBase
{
private:
    costRefList vector<double>;
    costList vector<double>;

public:
    // Constructors
    Suppliant();
    Suppliant(vector<double>, vector<double>);

    // Getters
    vector<double> get_costRefList();
    vector<double> get_costList();

    // Setters
    void set_costRefList(vector<double>);
    void set_costList(vector<double>);
    
    // Methods
    void print() override;
    
    // Destructor
    ~Suppliant();
}

#endif