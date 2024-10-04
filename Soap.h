#ifndef SOAP_H
#define SOAP_H

#include <iostream>
#include <string>

#include "Printable.h"
#include "Item.h"

using namespace std;

class Soap : public Item
{
public:
    string soapType;

private:
    // Constructors
    Soap(int numItem, double price, string brand, string soapType);
    Soap();

    // Getters
    string get_soapType() const;

    // Setters
    void set_soapType(string);
    
    // Methods
    void print() override;

    // Destructor
    ~Soap() override;
};

#endif