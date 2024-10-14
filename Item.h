#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

#include "Printable.h"

using namespace std;

class Item : public Printable
{
protected:
    int numItem;
    double price;
    string brand;
    bool isPerishableItem;

public:
    // Constructors
    Item(int numItem, double price, string brand, bool isPerishableItem);
    Item();

    // Getters
    int get_numItem() const;
    double get_price() const;
    string get_brand() const;
    bool get_isPerishableItem() const;

    // Setters
    void set_numItem(int);
    void set_price(double);
    void set_brand(string);
    void set_isPerishableItem(bool a);

    // Methods
    void print() override;
    virtual void change_numItem(int n);
    virtual void sellItem(int n);
    virtual void updateItem();

    virtual int get_shelfLifeInDay();
    virtual int *get_expirationList();
    virtual void set_expirationList(int *n);

    // Destructor
    ~Item();
};

#endif