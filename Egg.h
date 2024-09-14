#ifndef EGG_H
#define EGG_H
#include <iostream>
#include "Item.h"
class Egg:public Item{
    private:
        bool isCaged;
    public:
        Egg(int n, bool isCaged,double p);
        void print();
};

#endif