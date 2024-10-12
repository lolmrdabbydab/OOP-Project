#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <limits>
#include <ctime>
#include <vector>

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

// g++ --std=c++11 main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp -o a
// clang++ --std=c++11 main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp -o a

int main()
{
    //system("clear");

    /* -------------------------
        -= Read Data.txt File =-
    ------------------------- */
    string haveAccount;
    ifstream ReadFile("data.txt"); // Assign found "data.txt" to variable: ReadFile
    getline(ReadFile, haveAccount);

    /* -------------------------
        -= Set-up Suppliant =-
    ------------------------- */
    Suppliant suppliant = Suppliant();
    string *itemsName = new string[10];
    itemsName = suppliant.get_itemNames();

    /* -------------------------
        -= Set-up Store =-
    ------------------------- */
    Store store = Store();
    if (stoi(haveAccount) == 1)
    {
        suppliant.updateCost(); // Update costList (Saved -> Made past Day 1 -> Default costList must be change)

        /* -------------------------
        -= Set-up Store Status =-
        ------------------------- */
        string currentDay;
        getline(ReadFile, currentDay);
        store.set_currentDay(stoi(currentDay));

        string balance;
        getline(ReadFile, balance);
        store.set_balance(stod(balance));

        string rating;
        getline(ReadFile, rating);
        store.set_rating(stod(rating));

        string target;
        getline(ReadFile, target);
        store.set_target(stod(target));

        string numCustomer;
        getline(ReadFile, numCustomer);
        store.set_numCustomer(stoi(numCustomer));

        /* -------------------------
        -= Set-up Store's Inventory =-
        ------------------------- */
        for (int i = 0; i < 10; i++)
        {
            if (i > 5) // For Non-Perishable Item
            {
                string numItem;
                const string itemName = itemsName[i];

                getline(ReadFile, numItem);
                store.get_inventory()[itemName]->set_numItem(stoi(numItem));
            }
            else // For Perishable Item
            {
                string line;
                string word;
                vector<string> information;
                const string itemName = itemsName[i];

                getline(ReadFile, line);
                stringstream wordsInLine(line);

                while (wordsInLine >> word)
                {
                    information.push_back(word);
                }

                /* ----------------------------------------------------
                -= Set-up Perishable Item's numItem & expirationList =-
                ---------------------------------------------------- */
                store.get_inventory()[itemName]->set_numItem(stoi(information.at(1)));

                int shelfLifeInDay = stoi(information.at(0));
                int *expirationList = new int[shelfLifeInDay];
                int index = 0;

                for (int j = 2; j < information.size(); j++)
                {
                    expirationList[index] = stoi(information[j]);
                    index++;
                }
                store.get_inventory()[itemName]->set_expirationList(expirationList);
                
                delete[] expirationList;
            }
        }
    }
    ReadFile.close();

    /* -----------------------------
    -= Set-Up Store Data Variable =-
    ----------------------------- */
    double balance = store.get_balance();
    double rating = store.get_rating();
    double target = store.get_target();
    int currentDay = store.get_currentDay();
    int numCustomer = store.get_numCustomer();

    /* -------------------------
    -= Finish Set-up & Run Game =-
    ------------------------- */
    cout << "-= Welcome to The Retail Simulator Game =-" << endl;
    // Introduction Prompt

    /* -------------------------
    -= User Store Purchasing =-
    ------------------------- */
    bool running = true;
    while (running)
    {
        srand(time(nullptr)); // Randomize Time
        cout << "\n-------------------------------" << endl;
        cout << "\tWelcome to day " << currentDay << endl;
        cout << "-------------------------------\n" << endl;
        cout << "* Current Balance: $" << balance << endl;
        cout << "* Balance Target: $" << target << endl;
        cout << "-------------------------------\n" << endl;

        double *costList = new double[10];
        costList = suppliant.get_costList();

        cout << "-----> Buying goods for day " << currentDay << " <-----" << endl;
        suppliant.print();

        /* -------------------------
        -= Purchase Input Handling =-
        ------------------------- */
        while (true)
        {
            /* -------------------------
                -= Choosing Item =-
           ------------------------- */
            int itemNum;
            int itemIndex;
            cout << "\nPlease choose items to buy (1-10) (Enter any other numbers to stop purchase): ";

            while (!(cin >> itemNum)) // Loop until an int input
            {
                cout << "Invalid input type. Please enter an integer from (1-10): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (itemNum < 1 || itemNum > 10) // Stop input request if input number not in range
            {
                break;
            }
            itemIndex = itemNum - 1;

            /* -------------------------
             -= Choosing Item Amount =-
           ------------------------- */
            int amount;
            cout << "Amount: ";

            while (!(cin >> amount)) // Loop until an int input
            {
                cout << "Invalid input type. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (amount * costList[itemIndex] > balance) // Insufficient fund for purchase
            {
                cout << "Not enough money!!!" << endl;
            }
            else // Add purchase to Store's inventory
            {
                string itemName = itemsName[itemIndex];
                map<string, Item *> inventory = store.get_inventory();

                auto itr = inventory.find(itemName);
                if (itr != inventory.end()) // Check if itemName is found
                {
                    itr->second->change_numItem(amount);
                    balance -= costList[itemIndex] * amount;
                    cout << "\n* Remaining Balance: $" << balance << " *" << endl;
                }
            }
        }

        /* -------------------------
                -= Run Day =-
        ------------------------- */

        sleep(1);

        cout << "\n========--------- " << "Simulating Day " << store.get_currentDay() << " ---------========" << endl;

        sleep(2);

        /* -------------------------
          -= Randomise Purchase =-
        ------------------------- */
        for (int i = 0; i < numCustomer; i++)
        {
            int good = rand() % 10;                   // Randomise Good (Index)
            int numGoodBuy = rand() % currentDay + 1; // Randomise Amount of Good to Buy

            cout << "\n----> Customer (" << i + 1 << ") want to buy \"" << numGoodBuy << " " << suppliant.get_itemNames()[good] << "\"" << endl;

            /* ------------------------------------------
            -= Update Inventory & Rating after Purchase =-
            ------------------------------------------ */
            map<string, Item *> inventory = store.get_inventory();
            auto itr = inventory.find(itemsName[good]);

            if (itr != inventory.end()) // Check if good is found in inventory
            {
                Item* item = itr->second;
                int availableItems = item->get_numItem();

                if (availableItems >= numGoodBuy) // If there's enough goods in stock
                {
                    balance += numGoodBuy * item->get_price();
                    item->change_numItem(-numGoodBuy);
                    item->sellItem(numGoodBuy);
                    rating = min(rating + 0.3, 5.0); // Ensure rating doesn't exceed 5
                }
                else // If there's not enough goods in stock
                {
                    rating -= 0.5 * (numGoodBuy - availableItems); // Rating drop -> 0.5 * amount of unavaliable goods
                    rating = max(rating, 0.0);                     // Ensure rating doesn't drop below 0
                    balance += availableItems * item->get_price();
                    item->sellItem(item->get_numItem()); // Sell all avaliable stock
                    item->set_numItem(0);
                }
            }

            /* -------------------------
                -= Day Summary =-
            ------------------------- */
            cout << "\n=======-------- Store Status (End of Day " << store.get_currentDay() << ") --------=======\n"
                 << endl;
            cout << "* Balance: $" << balance << endl;
            cout << "* Rating (Stars): " << rating << endl;
            sleep(2);
        }

        cout << "\n=======-------- Final Verdict --------=======\n"
             << endl;
        if (balance < target)
        {
            ofstream MyFile("data.txt");
            MyFile << 0;
            MyFile.close();

            cout << "----> You failed to meet Day " << store.get_currentDay() << " target balance of $" << store.get_target() << "\n----> Your store faces bankruptcy!!!" << endl;
            running = false;
        }
        else if (rating <= 0)
        {
            ofstream MyFile("data.txt");
            MyFile << 0;
            MyFile.close();

            cout << "----> Your store rating reaches 0. Nobody wants to buy from you and you closed down!" << endl;
            running = false;
        }
        else
        {
            cout << "----> You made it through Day " << store.get_currentDay() << endl;
            cout << "\nChose one of the following option to proceed: " << endl;
            cout << "\t1. Play the next day" << endl;
            cout << "\t2. Save and exit" << endl;
            cout << "\nHow would you like to proceed (Enter 1 or 2): ";

            int choice;
            while (true)
            {
                if (cin >> choice && (choice == 1 || choice == 2))
                {
                    break;
                }

                cout << "Invalid input type. Please enter an integer (1 or 2): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            /* ----------------------------
            -= Update Suppliant & Store =-
            ---------------------------- */
            suppliant.updateCost();
            store.updateStore();
            store.set_balance(balance);
            store.set_rating(rating);

            /* ----------------------------
            -= Save Progress to Data.txt =-
            ---------------------------- */

            if (choice == 2)
            {
                ofstream MyFile("data.txt");
                MyFile << 1 << endl;
                MyFile << store.get_currentDay() << endl;
                MyFile << store.get_balance() << endl;
                MyFile << store.get_rating() << endl;
                MyFile << store.get_target() << endl;
                MyFile << store.get_numCustomer() << endl;

                map<string, Item*> inventory = store.get_inventory();

                /* ----------------------------
                -= Testing Inventory =-
                ---------------------------- */

                /* -----------------------------------
                -= Save Store Inventory to Data.txt =-
                ----------------------------------- */
                for (auto i = inventory.begin(); i != inventory.end(); i++)
                {
                    Item* item = i->second;
                    if (item->get_isPerishableItem()) // Save perishable Item data
                    {
                        int shelfLifeInDay = item->get_shelfLifeInDay();
                        int* expirationList = item->get_expirationList();
                        //cout << shelfLifeInDay << endl;
                        
                        MyFile << shelfLifeInDay << " " << item->get_numItem() << " ";
                        for (int j = 0; j < shelfLifeInDay; j++)
                        {
                            MyFile << expirationList[j] << " ";
                        }
                    }
                    else // Save non-perishable Item data
                    {
                        MyFile << item->get_numItem();
                    }
                    MyFile << "\n";
                }
                MyFile.close();

                cout << "Game Status Saved successfully!!!" << endl;
                running = false;
            }
        }
    }
    // delete[] itemsName;

    return 0;
}
