#ifndef TOY_H
#define TOY_H

#include <string>

#include "Printable.h"
#include "Item.h"

using namespace std;

class Toy : public Item
{
public:
    string toyType;
    string minAgeRestriction;

private:
    // Constructors
    Toy(int numItem, double price, string brand, string toyType, string minAgeRestriction);
    Toy();

    // Getters
    string get_toyType() const;
    string get_minAgeRestriction() const;

    // Setters
    void set_toyType(string);
    void set_minAgeRestriction(string);

    // Methods
    void print() override;

    // Destructor
    ~Toy() override;
};

#endif