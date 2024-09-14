#ifndef STOREBASE_H
#define STOREBASE_H
#include <iostream>
#include "Printable.h"
#include "Item.h"
class StoreBase: public Printable{
    private:
        int numberOfItemtypes = 6;
        Item** items = new Item*[6];
    protected:
        std::string nameItems[6]={"12 Caged Eggs","12 Free Range Eggs","A bottle of Cow Milk","A bottle of plant-based milk","Beef","Chicken"};
    public:
        StoreBase();
        StoreBase(int i0,int i1,int i2,int i3,int i4,int i5);
        Item** getItems();
        virtual void print();
        std::string * getNameItems();
        ~StoreBase();
};

#endif