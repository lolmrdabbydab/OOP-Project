#ifndef MEAT_H
#define MEAT_H
#include <string>
#include "PerishableItem.h"
#include "Item.h"
#include "Printable.h"
using namespace std;

class Meat : public PerishableItem
{
public:
    string fromAnimal;
    string bodyPart;

private:
    Meat(string, string);
    string get_fromAnimal();
    void set_fromAnimal(string fromAnimal);
    string get_bodyPart();
    void set_bodyPart(string bodyPart);
    void print() override;
};
#endif