#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Printable.h"
class Item:public Printable{
    private:
        int numberOfItems;
    public: 
        Item();
        int getNumberOfItems();
        void setNumberOfItems(int n);
        ~Item();
}

#endif