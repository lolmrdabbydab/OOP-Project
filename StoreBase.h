#ifndef STOREBASE_H
#define STOREBASE_H

#include <iostream>
#include "Printable.h"
#include "Item.h"
#include <map>

class StoreBase{
    private:
        int numDifferentItem;
        std::map<std::string,Item*> inventory;
    public:
        StoreBase();
        int get_numDifferentItem();
        std::map<std::string,Item*> get_inventory();
        void set_numDifferentItem();
        void updateItem(std::string itemName, int amount);
        void update_nunumDifferentItem(int n);
        void addItem(std::pair<std::string,Item*>);
        void removeItem();
        void print();
        ~StoreBase();
        
}


#endif