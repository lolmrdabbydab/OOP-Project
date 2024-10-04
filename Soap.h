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
    Soap(string);
    Soap();

    // Getters
    string get_soapType();

    // Setters
    void set_soapType(string soapType);
    
    // Methods
    void print() override;

    // Destructor
    ~Soap();
};

#endif