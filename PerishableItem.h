#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include <iostream>
#include "Item.h"
#include "Printable.h"
class PerishableItem: public Item{
    private:
        int shelfLifeInDay;
        int* expirationList;
    public:
        PerishableItem(int numItem,double price,std::string brand,bool isFromAnimal,int shelfLifeInday);
        int get_shelfLifeInDay();
        void set_shelfLifeInDay(int n);
        int* get_expirationList();
        void set_expirationList(int*);
        virtual void print();
        void sellItem(int n);
        void updateItem();
        ~PerisableItem();
};
#endif