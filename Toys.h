#ifndef TOYS_H
#define TOYS_H

#include <string>

#include "Item.h"
#include "Printable.h"

using namespace std;

class Toys : public Item
{
public:
    string toyType;
    string minAgeRestriction;

private:
    Toys(string, string);
    
    string get_toyType();
    string get_minAgeRestriction();

    void set_toyType(string toyType);
    void set_minAgeRestriction(string minAgeRestriction);
    
    void print() override;
};
#endif