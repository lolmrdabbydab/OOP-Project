#ifndef EGG_H
#define EGG_H
#include "PerishableItem.h"
#include "Printable.h"
#include "Item.h"
#include <string>
using namespace std;
class Egg : public PerishableItem
{
public:
    string fromAnimal;
    string eggType;

private:
    Egg(string, string);
    string get_fromAnimal();
    void set_fromAnimal(string fromAnimal);
    string get_eggType();
    void set_eggType(string eggType);
    void print() override;
};
#endif