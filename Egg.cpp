#include "Egg.h"
#include <string>
using namespace std;

Egg::Egg(string, string) : PerishableItem(shelfLifeinDay, expiration), fromAnimal(fromAnimal), eggType(eggType) {};
string Egg::get_fromAnimal()
{
    return fromAnimal;
}
void Egg::set_fromAnimal(string fromAnimal)
{
    this->fromAnimal = fromAnimal;
}
string Egg::get_eggType()
{
    return eggType;
}
void Egg::set_eggType(string eggType)
{
    this->eggType = eggType;
}
void Egg::print() {}