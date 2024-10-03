#include "Egg.h"
#include "PerishableItem.h"
#include "Printable.h"
#include "Item.h"
#include <string>
using namespace std;

Egg::Egg(string fromAnimal, string eggType) : Perishable(shelfLifeinDay, expiration), fromAnimal(fromAnimal), eggType(eggType);
string Egg::get_fromAnimal()
{
    return fromAnimal;
}
void Egg::set_fromAnimal(string fromAnimal)
{
    this-> fromAnimal = fromAnimal;
}
string Egg::get_eggType()
{
    return eggType;
}
void Egg::set_eggType(string eggType)
{
    this->eggType = eggType;
}

