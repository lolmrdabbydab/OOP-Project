#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include <iostream>
#include "Item.h"
#include "Printable.h"
class PerishableItem : public Item
{
private:
    int shelfLifeInDay;
    int* expirationList;

public:
    // Constructors
    PerishableItem(int numItem, double price, std::string brand, bool isPerishable, int shelfLifeInDay);
    
    // Getters
    int get_shelfLifeInDay();
    int *get_expirationList();
    
    // Setters
    void set_shelfLifeInDay(int n);
    void set_expirationList(int* nList);
    
    // Methods
    virtual void print();
    void sellItem(int n);
    void updateItem();
    
    // Destructor
    ~PerishableItem();
};
#endif