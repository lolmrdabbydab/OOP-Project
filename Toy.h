#ifndef TOY_H
#define TOY_H

#include <string>

#include "Printable.h"
#include "Item.h"

using namespace std;

class Toy : public Item
{
private:
    string toyType;
    int minAgeRestriction;

public:
    // Constructors
    Toy(int numItem, double price, string brand, bool isPerishableItem, string toyType, int minAgeRestriction);

    // Getters
    string get_toyType() const;
    int get_minAgeRestriction() const;

    // Setters
    void set_toyType(string);
    void set_minAgeRestriction(int);

    // Methods
    void print() override;
    void change_numItem(int n) override;

    // Destructor
    ~Toy();
};

#endif