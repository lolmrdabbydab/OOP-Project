#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Printable.h"
class Item:public Printable{
    private:
        int numberOfItems;
        double price;
    public: 
        Item(int n,double p);
        double getPrice();
        int getNumberOfItems();
        void setNumberOfItems(int n);
        void changeAmount(int n);
};

#endif