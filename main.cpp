#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <limits>
#include <ctime>
#include <vector>
#include <map>
#include <set>
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

int main()
{
    bool restart = false;
    do
    {
        system("clear");

        /* -------------------------------
           -= Set-up Store & Suppliant =-
        ------------------------------- */

        Store store = Store();
        Suppliant suppliant = Suppliant();
        string *itemsName = new string[10];

        for (int j = 0; j < 10; j++)
        {
            itemsName[j] = suppliant.get_itemNames()[j];
        }

        /* -------------------------------
                -= Introduction =-
        ------------------------------- */

        string choice;

        cout << "\t\t\t|====================================================================================================|" << endl;
        cout << "\t\t\t|====----------------------      Welcome to The Retail Simulator Game      ----------------------====|" << endl;
        cout << "\t\t\t|====================================================================================================|" << endl;
        cout << "\nWould you like to see the game introduction? (y/n): ";

        // Error handling for user input
        while (!(cin >> choice) || (choice != "y" && choice != "n"))
        {
            cout << "Invalid input. Please enter (y/n): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == "y")
        {
            cout << "\n--------------------------------- Introduction -----------------------------------" << endl;
            cout << "In this game, you will manage a store, purchase stock, and keep customers happy.\n"
                 << "Your goal is to maintain profitability and avoid bankruptcy!\n";
        }
        cout << "----------------------------------------------------------------------------------\n"
             << endl;

        /* -------------------------
          -= Choosing Progression =-
        ------------------------- */

        if (!restart) // If user has previously chosen to start new game
        {
            string input;

            cout << "Would you like to:\n";
            cout << "\t1. Start a new game\n";
            cout << "\t2. Continue from where you left off\n";
            cout << "Enter your choice (1 or 2): ";

            while (cin >> input && (input != "1" && input != "2"))
            {
                cout << "Invalid input. Please enter (1 or 2): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int gameProgressChoice = stoi(input);
            
            if (gameProgressChoice == 1)
            {
                ofstream MyFile("data.txt"); // Ensure data.txt is available
                MyFile << 0 << endl;         // Ensure data.txt has default starting data
                MyFile.close();
            }
            else if (gameProgressChoice == 2)
            {
                /* -------------------------
                -= Read & Use Data.txt File =-
                ------------------------- */

                string haveAccount;
                ifstream ReadFile("data.txt"); // Assign found "data.txt" to variable: ReadFile
                getline(ReadFile, haveAccount);

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
                        string line;
                        string word;
                        vector<string> information;

                        getline(ReadFile, line);
                        stringstream wordsInLine(line);

                        while (wordsInLine >> word)
                        {
                            information.push_back(word);
                        }
                        if (store.get_inventory()[itemsName[stoi(information.at(0))]]->get_isPerishableItem() == false) // For Non-Perishable Item
                        {
                            store.get_inventory()[itemsName[stoi(information.at(0))]]->set_numItem(stoi(information.at(1)));
                        }
                        else // For Perishable Item
                        {
                            /* ----------------------------------------------------
                            -= Set-up Perishable Item's numItem & expirationList =-
                            ---------------------------------------------------- */

                            store.get_inventory()[itemsName[stoi(information.at(0))]]->set_numItem(stoi(information.at(1)));

                            int shelfLifeInDay = store.get_inventory()[itemsName[stoi(information.at(0))]]->get_shelfLifeInDay();
                            int *expirationList = new int[shelfLifeInDay];
                            int index = 0;

                            for (int j = 2; j < information.size(); j++)
                            {
                                expirationList[index] = stoi(information[j]);
                                index++;
                            }
                            store.get_inventory()[itemsName[stoi(information.at(0))]]->set_expirationList(expirationList);

                            delete[] expirationList;
                        }
                    }
                }
                ReadFile.close();
            }
        }

        /* -----------------------------
        -= Set-Up Store Data Variable =-
        ----------------------------- */

        store.set_balance(100000);
        double balance = store.get_balance();
        double rating = store.get_rating();
        double target = store.get_target();
        int currentDay = store.get_currentDay();
        int numCustomer = store.get_numCustomer();

        /* -------------------------
        -= User Store Purchasing =-
        ------------------------- */

        bool running = true;
        while (running)
        {
            srand(time(nullptr)); // Randomize Time

            int countPurchase = 0;
            double *costList = new double[10];

            for (int j = 0; j < 10; j++)
            {
                costList[j] = suppliant.get_costList()[j]; // Update costList with randomized cost based on costRefList
            }

            /* -------------------------
            -= Purchase Input Handling =-
            ------------------------- */
            bool buying = true;
            while (buying)
            {
                system("clear");

                cout << "\n\t\t\t-------------------------------" << endl;
                cout << "\t\t\t\tWelcome to day " << currentDay << endl;
                cout << "\t\t\t-------------------------------\n"
                     << endl;

                /* -----------------------------------
                -= Show Inventory & Suppliant Shop =-
                ----------------------------------- */

                cout << "------------------->>>>>>>> Buying Goods for Day " << currentDay << " <<<<<<<<-----------------------" << endl;
                store.print();
                suppliant.print();

                /* -------------------------
                    -= Choosing Item =-
                ------------------------- */

                set<string> validInputs = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "n"};
                string input;

                while (true)
                {
                    cout << "\n\nPlease choose items to buy (1-10) (Enter 'n' to stop purchase): ";
                    while (true) // Ask until string input from 1-10 or n
                    {
                        cin >> input;
                        if (validInputs.find(input) == validInputs.end())
                        {
                            cout << "Invalid input. Please enter a number between 1 and 10: ";
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (input == "n") // Check if user didn't have any purchases
                    {
                        if (countPurchase == 0)
                        {
                            string confirm;
                            cout << "\nAre you sure you want to proceed without buying any items? (y/n): ";

                            while (!(cin >> confirm) || (confirm != "y" && confirm != "n"))
                            {
                                cout << "Invalid input. Please enter 'y' or 'n': ";
                            }

                            if (confirm == "y")
                            {
                                buying = false;
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            buying = false;
                            break;
                        }
                    }

                    /* -------------------------
                    -= Choosing Item Amount =-
                    ------------------------- */

                    int itemNum = stoi(input);
                    int itemIndex = itemNum - 1;
                    int amount;
                    cout << "Amount: ";

                    while (true) // Ask until a valid non-negative integer is entered
                    {
                        if (cin >> amount && amount >= 0)
                        {
                            break;
                        }

                        cout << "Invalid Amount. Please enter a non-negative integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (amount * costList[itemIndex] > balance) // Insufficient fund for purchase
                    {
                        cout << "Not enough money!!!" << endl;
                    }
                    else // Add purchase to Store's inventory
                    {
                        countPurchase++;
                        string itemName = itemsName[itemIndex];
                        map<string, Item *> inventory = store.get_inventory();
                        auto itr = inventory.find(itemName);
                        Item *item = itr->second;

                        if (itr != inventory.end()) // Check if itemName is found
                        {
                            item->change_numItem(amount); // Change Item's numItem count

                            if (item->get_isPerishableItem()) // Adjust expirationList for new PerishableItem
                            {
                                int expLength = item->get_shelfLifeInDay();
                                int *tmp = new int[expLength];

                                for (int j = 0; j < expLength; j++)
                                {
                                    tmp[j] = item->get_expirationList()[j];
                                }

                                tmp[expLength - 1] += amount;
                                item->set_expirationList(tmp);
                                delete[] tmp;
                            }

                            balance -= costList[itemIndex] * amount; // Decrease balance from purchase
                            cout << "\n* Remaining Balance: $" << balance << " *" << endl;
                        }
                    }
                }
            }

            /* -------------------------
                    -= Run Day =-
            ------------------------- */

            sleep(1);

            cout << "\n========--------- " << "Simulating Day " << store.get_currentDay() << " ---------========" << endl;

            sleep(2);

            /* ----------------------------
                -= Randomise Purchase =-
            ---------------------------- */

            for (int i = 0; i < numCustomer; i++)
            {
                int good = rand() % 10;                   // Randomise Good (Index)
                int numGoodBuy = rand() % currentDay + 1; // Randomise Amount of Good to Buy

                /* ------------------------------------------
                -= Update Inventory & Rating after Purchase =-
                ------------------------------------------ */

                map<string, Item *> inventory = store.get_inventory();
                auto itr = inventory.find(itemsName[good]);

                if (itr != inventory.end()) // Check if good is found in inventory
                {
                    Item *item = itr->second;
                    int availableItems = item->get_numItem();
                    double tempRating = rating;

                    if (availableItems >= numGoodBuy) // If there's enough goods in stock
                    {
                        balance += numGoodBuy * item->get_price();
                        item->change_numItem(-numGoodBuy);
                        item->sellItem(numGoodBuy);
                        rating = min(rating + 0.3, 5.0); // Ensure rating doesn't exceed 5

                        cout << "\n----> Customer (" << i + 1 << ") bought " << numGoodBuy << " \"" << suppliant.get_itemNames()[good] << "\"" << endl;
                        cout << "\t----> Rating increased from: " << tempRating << " -> " << rating << " stars" << endl;
                    }
                    else // If there's not enough goods in stock
                    {
                        rating -= 0.5 * (numGoodBuy - availableItems); // Rating drop -> 0.5 * amount of unavaliable goods
                        rating = max(rating, 0.0);                     // Ensure rating doesn't drop below 0
                        balance += availableItems * item->get_price();
                        item->sellItem(item->get_numItem()); // Sell all available stock
                        item->set_numItem(0);

                        cout << "\n----> Customer (" << i + 1 << ") wanted to buy " << numGoodBuy << " \"" << suppliant.get_itemNames()[good] << "\" but there were " << availableItems << " in stock" << endl;
                        cout << "\t----> Rating decreased from: " << tempRating << " -> " << rating << " stars" << endl;
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
            if (balance < target) // Fail due having less money than target
            {
                ofstream MyFile("data.txt");
                MyFile << 0;
                MyFile.close();

                cout << "----> You failed to meet Day " << store.get_currentDay() << " target balance of $" << store.get_target() << "\n----> Your store faces bankruptcy!!!" << endl;
                running = false;
            }
            else if (rating <= 0) // Fail due having bad rating (<=0)
            {
                ofstream MyFile("data.txt");
                MyFile << 0;
                MyFile.close();

                cout << "----> Your store rating reaches 0. Nobody wants to buy from you and you closed down!" << endl;
                running = false;
            }
            else // Survived the day
            {
                cout << "----> You made it through Day " << store.get_currentDay() << endl;
                cout << "\nChose one of the following option to proceed: " << endl;
                cout << "\t1. Play the next day" << endl;
                cout << "\t2. Save and exit" << endl;
                cout << "\t3. Start new game" << endl;
                cout << "\nHow would you like to proceed (Enter 1, 2 or 3): ";

                int choice;
                while (true) // Progression option
                {
                    if (cin >> choice && ((choice == 1 || choice == 2) || (choice == 3)))
                    {
                        if (choice == 3)
                        {
                            ofstream MyFile("data.txt");
                            MyFile << 0 << endl; // Clear data.txt
                            MyFile.close();

                            running = false;
                            restart = true;
                        }

                        break;
                    }

                    cout << "Invalid input type. Please enter an integer (1, 2 or 3): ";
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
                delete[] costList;
                currentDay += 1;
                target += currentDay + 5 * (currentDay / 5);

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

                    map<string, Item *> inventory = store.get_inventory();

                    /* -----------------------------------
                    -= Save Store Inventory to Data.txt =-
                    ----------------------------------- */

                    for (auto i = inventory.begin(); i != inventory.end(); i++)
                    {
                        if (i->second->get_isPerishableItem()) // Save perishable Item data
                        {
                            int shelfLifeInDay = i->second->get_shelfLifeInDay();
                            int *expirationList = new int[10];
                            for (int j = 0; j < shelfLifeInDay; j++)
                            {
                                expirationList[j] = i->second->get_expirationList()[j];
                            }
                            for (int j = 0; j < 10; j++)
                            {
                                if (itemsName[j] == i->first)
                                {
                                    MyFile << j << " ";
                                    break;
                                }
                            }
                            MyFile << i->second->get_numItem() << " ";
                            for (int j = 0; j < shelfLifeInDay; j++)
                            {
                                MyFile << expirationList[j] << " ";
                            }
                            delete[] expirationList;
                        }
                        else // Save non-perishable Item data
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                if (itemsName[j] == i->first)
                                {
                                    MyFile << j << " ";
                                    break;
                                }
                            }
                            MyFile << i->second->get_numItem();
                        }
                        MyFile << "\n";
                    }
                    MyFile.close();

                    cout << "Game Status Saved successfully!!!" << endl;
                    restart = false;
                    running = false;
                }
            }
        }
        delete[] itemsName;
    } while (restart);

    return 0;
}