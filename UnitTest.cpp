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
#include "UnitTest.h"

/* -------------------
-= Test Implementation =-
------------------- */

// Constructor
UnitTest::UnitTest() {}

void UnitTest::test_storeSetUp()
{
    Store store;

    // Expected Values
    double expectedBalance = 30;
    double expectedRating = 5;
    double expectedTarget = 10;
    int expectedCurrentDay = 1;
    int expectedNumCustomer = 1;

    // Test and Output Results
    if (store.get_balance() != expectedBalance)
        throw string("Balance not initialized correctly. Expected: " + to_string(expectedBalance) + ", Actual: " + to_string(store.get_balance()));
    if (store.get_rating() != expectedRating)
        throw string("Rating not initialized correctly. Expected: " + to_string(expectedRating) + ", Actual: " + to_string(store.get_rating()));
    if (store.get_target() != expectedTarget)
        throw string("Target not initialized correctly. Expected: " + to_string(expectedTarget) + ", Actual: " + to_string(store.get_target()));
    if (store.get_currentDay() != expectedCurrentDay)
        throw string("Current day not initialized correctly. Expected: " + to_string(expectedCurrentDay) + ", Actual: " + to_string(store.get_currentDay()));
    if (store.get_numCustomer() != expectedNumCustomer)
        throw string("Number of customers not initialized correctly. Expected: " + to_string(expectedNumCustomer) + ", Actual: " + to_string(store.get_numCustomer()));
}

void UnitTest::test_suppliantSetUp()
{
    Suppliant suppliant;
    double expectedCostList[10] = {5, 5.5, 4, 4, 8, 12, 7, 7, 10, 11};
    double expectedCostRefList[10] = {5, 5.5, 4, 4, 8, 12, 7, 7, 10, 11};

    for (int i = 0; i < 10; i++)
    {
        if (suppliant.get_costList()[i] != expectedCostList[i])
            throw string("Suppliant costList[" + to_string(i) + "] not initialized correctly. Expected: " + to_string(expectedCostList[i]) + ", Actual: " + to_string(suppliant.get_costList()[i]));
        if (suppliant.get_costRefList()[i] != expectedCostRefList[i])
            throw string("Suppliant costRefList[" + to_string(i) + "] not initialized correctly. Expected: " + to_string(expectedCostRefList[i]) + ", Actual: " + to_string(suppliant.get_costRefList()[i]));
    }
}

void UnitTest::test_updatePerishableItem()
{
    PerishableItem item(10, 5, "Brand", true, 7);
    int expirationList[7] = {3, 2, 1, 0, 1, 2, 1};
    item.set_expirationList(expirationList);

    item.updateItem();

    int expectedExpirationList[7] = {2, 1, 0, 1, 2, 1, 0};
    for (int i = 0; i < 7; i++)
    {
        if (item.get_expirationList()[i] != expectedExpirationList[i])
            throw string("ExpirationList[" + to_string(i) + "] not updated correctly. Expected: " + to_string(expectedExpirationList[i]) + ", Actual: " + to_string(item.get_expirationList()[i]));
    }
    if (item.get_numItem() != 7)
        throw string("numItem not updated correctly after updateItem(). Expected: 7, Actual: " + to_string(item.get_numItem()));
}

void UnitTest::test_sellPerishableItem()
{
    PerishableItem item(10, 5, "Brand", true, 5);
    int expirationList[5] = {1, 2, 3, 3, 1};
    item.set_expirationList(expirationList);

    item.sellItem(3);

    int expectedExpirationList[5] = {0, 0, 3, 3, 1};
    for (int i = 0; i < 5; i++)
    {
        if (item.get_expirationList()[i] != expectedExpirationList[i])
            throw string("ExpirationList[" + to_string(i) + "] not updated correctly after sellItem(). Expected: " + to_string(expectedExpirationList[i]) + ", Actual: " + to_string(item.get_expirationList()[i]));
    }
}

void UnitTest::test_updateCost()
{
    Suppliant suppliant;
    double *originalCostList = suppliant.get_costList();

    suppliant.updateCost();

    for (int i = 0; i < 10; i++)
    {
        double minExpected = 0.5 * originalCostList[i];
        double maxExpected = 1.5 * originalCostList[i];
        if (suppliant.get_costList()[i] < minExpected || suppliant.get_costList()[i] > maxExpected)
            throw string("Cost[" + to_string(i) + "] not within expected range after updateCost(). Min: " + to_string(minExpected) + ", Max: " + to_string(maxExpected) + ", Actual: " + to_string(suppliant.get_costList()[i]));
    }
}

void UnitTest::test_updateStore()
{
    Store store;
    store.updateStore();

    if (store.get_currentDay() != 2)
        throw string("Current day not updated correctly. Expected: 2, Actual: " + to_string(store.get_currentDay()));
    if (store.get_numCustomer() != 1)
        throw string("Number of customers not updated correctly. Expected: 1, Actual: " + to_string(store.get_numCustomer()));
    if (store.get_target() <= 10)
        throw string("Target not updated correctly. Expected > 10, Actual: " + to_string(store.get_target()));
}

// Destructor
UnitTest::~UnitTest() {}

/* -------------------
    -= Test Code =-
------------------- */

int main()
{
    system("clear");

    UnitTest unitTest;
    bool allTestsPassed = true;

    /* --------------------
    -= test_storeSetUp() =-
    -------------------- */
    try
    {
        unitTest.test_storeSetUp();
        cout << "test_storeSetUp() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_storeSetUp() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    /* ------------------------
    -= test_suppliantSetUp() =-
    ------------------------ */
    try
    {
        unitTest.test_suppliantSetUp();
        cout << "test_suppliantSetUp() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_suppliantSetUp() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    /* ------------------------------
    -= test_updatePerishableItem() =-
    ------------------------------ */
    try
    {
        unitTest.test_updatePerishableItem();
        cout << "test_updatePerishableItem() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_updatePerishableItem() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    /* ----------------------------
    -= test_sellPerishableItem() =-
    ---------------------------- */
    try
    {
        unitTest.test_sellPerishableItem();
        cout << "test_sellPerishableItem() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_sellPerishableItem() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    /* -------------------
    -= test_updateCost() =-
    ------------------- */
    try
    {
        unitTest.test_updateCost();
        cout << "test_updateCost() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_updateCost() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    /* -------------------
    -= test_updateStore() =-
    ------------------- */
    try
    {
        unitTest.test_updateStore();
        cout << "test_updateStore() passed." << endl;
    }
    catch (string errMsg)
    {
        cerr << "test_updateStore() failed: " << errMsg << endl;
        allTestsPassed = false;
    }

    // Summary
    if (allTestsPassed)
    {
        cout << "\nAll tests passed successfully!" << endl;
    }
    else
    {
        cout << "\nSome tests failed. Check the error." << endl;
    }

    return 0;
}