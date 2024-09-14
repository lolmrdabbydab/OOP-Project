#ifndef MEAT_H
#define MEAT_H
#include <iostream>
#include "Item.h"
class Meat:public Item{
    private:
    public: 
        Meat(int n,double p);
        void print();
};
#endif