#include "Soap.h"
#include <string>
using namespace std;

Soap::Soap(string), Item(numItem, price, brand), soapType(soapType) {};
string Soap::get_soapTpye()
{
    return soapType;
}
void Soap::set_soapTpye(string soapType)
{
    this->soapType = soapType;
}
void Soap::infoSummary() {}
void Soap::print() {}