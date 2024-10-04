#ifndef STOREBASE_H
#define STOREBASE_H

#include <iostream>
#include "Printable.h"
#include "Item.h"
#include <map>

class StoreBase: public Printable{
    private:
        int numDifferentItem;
        std::map<std::string,Item*> inventory;
    public:
        StoreBase();
        int get_numDifferentItem();
        std::map<std::string,Item*> get_inventory();

        void set_numDifferentItem(int n);
        void set_inventory(std::map<std::string,Item*> );
        void change_numDifferentItem(int n);
        void addItem(std::pair<std::string,Item*>);
        void removeItem(std::string);
        virtual void print();

        ~StoreBase();
}; 

#endif