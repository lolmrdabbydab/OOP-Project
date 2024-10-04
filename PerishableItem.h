#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include <iostream>
#include "Item.h"
#include "Printable.h"
class PerisableItem: public Item{
    private:
        int shelfLifeInDay;
        int* expirationList;
    public:
        PerisableItem();
        int get_shelfLifeInDay();
        void set_shelfLifeInDay(int n);
        int* get_expirationList();
        void set_expirationList(int*);
        virtual void print();
        ~PerisableItem();
};
#endif