#ifndef TOYS_H
#define TOYS_H
#include "Item.h"
#include "Printable.h"
#include <string>
using namespace std;
class Toys : public Item
{
public:
    string toyTpye;
    string minAgeRestriction;

private:
    Toys(string, string);
    string get_toyTpye();
    void set_toyTpye(string toyTpye);
    string get_minAgeRestriction();
    void set_minAgeRestriction(string minAgeRestriction);
    void print() override;
};
#endif