#ifndef STOREBASE_H
#define STOREBASE_H
#include <iostream>
#include "Printable.h"
#include "Item.h"
class StoreBase: public Printable{
    public:
        int numberOfItemtypes = 6;
        Item** items = new Item*[6];
    protected:
        std::string nameItems[6];
        nameItems[0] = "12 Caged Eggs";
        nameItems[1] = "12 Free Range Eggs";
        nameItems[2] = "A bottle of Cow Milk";
        nameItems[3] = "A bottle of plant-based milk";
        nameItems[4] = "Beef";
        nameItems[5] = "Chicken";
    private:
        StoreBase();
        StoreBase(int i0,int i1,int i2,int i3,int i4,int i5);
        Item** getItems();
        virtual void print();
        ~StoreBase();
};

#endif