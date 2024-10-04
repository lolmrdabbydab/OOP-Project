#ifndef SOAP_H
#define SOAP_H
#include "Item.h"
#include "Printable.h"
#include <string>
using namespace std;
class Soap : public Item
{
public:
    string soapType;

private:
    Soap(string);
    string get_soapTpye();
    void set_soapTpye(string soapTpye);
    void infoSummary() override;
    void print() override;
};
#endif