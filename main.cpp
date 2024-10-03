#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract class Printable, providing the print interface for derived classes.
class Printable
{
public:
    virtual void print() = 0; // Pure virtual function to enforce printing behavior in all derived classes.
};

// Class Item represents the base class for all items in the store. 
class Item : public Printable
{
protected:
    int numItem;
    string expDate;
    string brand;

public:
    Item(int num, const string& exp, const string& br) 
        : numItem(num), expDate(exp), brand(br) {}

    // Virtual function to allow derived classes to print their specific details.
    virtual void print() override
    {
        cout << "Item Brand: " << brand << ", Expiration Date: " << expDate << ", Stock: " << numItem << endl;
    }
};

// Egg class inherits from Item and adds specific attributes like animalEgg and eggType.
class Egg : public Item
{
private:
    string animalEgg;
    string eggType;

public:
    Egg(int num, const string& exp, const string& br, const string& animal, const string& type)
        : Item(num, exp, br), animalEgg(animal), eggType(type) {}

    // Override the print function to include specific information about eggs.
    void print() override
    {
        Item::print();
        cout << "Animal Egg: " << animalEgg << ", Egg Type: " << eggType << endl;
    }
};

// Milk class inherits from Item but doesn't introduce new properties, so it relies on Item's functionality.
class Milk : public Item
{
public:
    Milk(int num, const string& exp, const string& br)
        : Item(num, exp, br) {}

    // Override print function to include specific information about milk.
    void print() override
    {
        Item::print();
        cout << "This is a milk product." << endl;
    }
};

// Store class contains a list of items, using polymorphism to print all types of items in the store.
class Store : public Printable
{
private:
    vector<Item*> itemList; // A list of pointers to Item objects.

public:
    Store() {}

    void addItem(Item* item)
    {
        itemList.push_back(item);
    }

    // Override the print function to display details for all items in the store.
    void print() override
    {
        cout << "Store Inventory:" << endl;
        for (auto item : itemList)
        {
            item->print();
        }
    }

    ~Store()
    {
        for (auto item : itemList)
        {
            delete item; // Clean up the dynamically allocated memory.
        }
    }
};

int main()
{
    // Create some items
    Egg egg1(10, "2024-12-01", "BrandA", "Chicken", "Organic");
    Milk milk1(20, "2024-11-10", "BrandB");

    // Create a store and add items to it
    Store store;
    store.addItem(new Egg(10, "2024-12-01", "BrandA", "Chicken", "Organic"));
    store.addItem(new Milk(20, "2024-11-10", "BrandB"));

    // Print the store inventory
    store.print();

    return 0;
}