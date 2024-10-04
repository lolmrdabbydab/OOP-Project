#include "Milk.h"
#include <string>
using namespace std;

Milk::Milk(string, string), PerishableItem(shelfLifeinDay, expiration), milksources(milksources), milkType(milkType) {};
string Milk::get_milksources()
{
    return milksources;
}
void Milk::set_milksources(string milksources)
{
    this->milksources = milksources;
}
string Milk::get_milkType()
{
    return milkType;
}
void Milk::set_milkType(string milkType)
{
    this->milkType = milkType;
}
void Milk::print() {}