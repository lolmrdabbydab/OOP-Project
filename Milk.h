#ifndef MILK_H
#define MILK_H
#include "PerishableItem.h"
#include "Printable.h" 
#include "Item.h"
#include <string>
using namespace std;
class Milk:public PerishableItem
{
public:
    string milksources;
    string milkType;
private:
    Milk(string milksources,string milkType);
    string get_milksources();
    void set_milksources(string milksources);
    string get_milkType();
    void set_milkType(string milkType);
    void print() override;
};
#endif