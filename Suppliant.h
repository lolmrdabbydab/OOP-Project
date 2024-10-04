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
    vector<double> costRefList;
    vector<double> costList;

public:
    // Constructors
    Suppliant(int, map<string, Item*>, vector<double>, vector<double>);
    Suppliant();

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
};

#endif