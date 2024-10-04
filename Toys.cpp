#include "Toys.h"
#include <string>
using namespace std;

Toys::Toys(string, string), Item(NumItem, price, brand), toyType(toyType), minAgeRestriction(minAgeRestriction) {};
string Toys::get_toyTpye()
{
    return toyTpye;
}
void Toys::set_toyTpye(string toyTpye)
{
    this->toyTpye = toyTpye;
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