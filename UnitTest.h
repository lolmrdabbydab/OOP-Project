#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <limits>
#include <ctime>
#include <vector>
#include <map>
#include <iomanip>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"
#include "Suppliant.h"
#include "Item.h"
#include "PerishableItem.h"
#include "Egg.h"
#include "Meat.h"
#include "Milk.h"
#include "Soap.h"
#include "Toy.h"

using namespace std;

class UnitTest
{
public:
    // Constructors
    UnitTest();

    // Methods
    void test_storeSetUp();           // Check if store's attributes are constructed correctly -> Important for game to run correctly
    void test_suppliantSetUp();       // Check if suppliant's attributes are constructed correctly -> Important for game to run correctly
    void test_updatePerishableItem(); // Check if the expirationList of PerishableItem are updated correctly
    void test_sellPerishableItem();   // Check if PerishableItem count are deducted and expirationList are changed correctly from purchase
    void test_updateCost();           // Check if the items' cost in costList is randomized correctly (within expected range limited by costRefList)
    void test_updateStore();          // Check if Store's attributes are updated correctly after a day passed to be ready for updated data usage the next day

    // Destructor
    ~UnitTest();
};

#endif
