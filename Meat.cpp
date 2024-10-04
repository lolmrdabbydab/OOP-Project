#include "Meat.h"
#include <string>
using namespace std;

Meat::Meat(string, string), PerishableItem(shelfLifeinDay, expirationList), fromAnimal(fromAnimal), bodyPart(bodyAnimal);
string Meat::get_fromAnimal()
{
    return fromAnimal;
}
void Meat::set_fromAnimal(string fromAnimal)
{
    this->fromAnimal = fromAnimal;
}
string Meat::get_bodyPart()
{
    return bodyPart;
}
void Meat::set_bodyPart(string bodyPart)
{
    this->bodyPart = bodyPart;
}
void Meat::print() {}