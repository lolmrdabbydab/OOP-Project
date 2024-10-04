#ifndef TOY_H
#define TOY_H

#include <string>

#include "Item.h"
#include "Printable.h"

using namespace std;

class Toy : public Item
{
public:
    string toyType;
    string minAgeRestriction;

private:
    // Constructors
    Toy(string, string);
    Toy();
    
    // Getters
    string get_toyType();
    string get_minAgeRestriction();

    // Setters
    void set_toyType(string toyType);
    void set_minAgeRestriction(string minAgeRestriction);
    
    // Methods
    void print() override;

    // Destructor
    ~Toy();
};
#endif