#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "StoreBase.h"
#include "Item.h"
class Store:public StoreBase{
    private:
        int currentDay;
        double balance;
        double rating;
        Item** items;
    public:
        Store();
        Store(int currentDay,double b, double r,int i0,int i1,int i2, int i3,int i4,int i5);
        double getBalance();
        void setBalance(double b);
        double getRating();
        void setRating(double r);
        int getDay();
        Item** getItems();
        ~Store();
        void print();
};

#endif