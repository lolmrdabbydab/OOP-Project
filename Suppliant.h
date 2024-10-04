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
    Suppliant(int numDifferentItem, map<string, Item*> inventory, vector<double> costRefList, vector<double> costList);
    Suppliant();

    // Getters
    vector<double> get_costRefList() const;
    vector<double> get_costList() const;

    // Setters
    void set_costRefList(vector<double>);
    void set_costList(vector<double>);

    // Methods
    void print() override;

    // Destructor
    ~Suppliant() override;
};

#endif