#include <iostream>
#include <string>

using namespace std;

class Printable
{
public:
    virtual void print() = 0;
};

class Store : public Printable
{
private:
    Item **itemList;

public:
    void print() override;

    Item** get_itemList() { return itemList; }
};

class Item : public Printable
{
protected:
    ;
    int numItem;
    string expDate;
    string brand;

public:
    void print() override;
};

class Egg : public Item
{
private:
    string animalEgg;
    string eggType;

public:
    void print() override;
};

class Milk : public Item
{
public:
    void print() override;
};