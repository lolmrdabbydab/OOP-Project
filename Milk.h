#ifndef MILK_H
#define MILK_H
#include <iostream>
#include "Item.h"
class Milk:public Item{
    private:
        std::string milkType;
    public:
        Milk(int n,std::string t,double p);
        void print();
};

#endif