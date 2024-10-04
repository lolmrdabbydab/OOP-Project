#include "Toys.h"
#include <string>
using namespace std;

Toys::Toys(string, string), Item(NumItem, price, brand), toyType(toyType), minAgeRestriction(minAgeRestriction) {};
string Toys::get_toyType()
{
    return toyType;
}
void Toys::set_toyType(string toyType)
{
    this->toyType = toyType;
}
string Toys::get_minAgeRestriction()
{
    return minAgeRestriction;
}
void Toys::set_minAgeRestriction(string minAgeRestriction)
{
    this->minAgeRestriction = minAgeRestriction;
}
void Toys::print() {};