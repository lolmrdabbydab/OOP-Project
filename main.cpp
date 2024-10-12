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
    system("clear");

    /* -------------------------
        -= Get Data File =-
    ------------------------- */
    string haveAccount;
    ifstream ReadFile("data.txt"); // Assign found "data.txt" to variable: ReadFile
    getline(ReadFile, haveAccount);

    /* -------------------------
        -= Set-up Suppliant =-
    ------------------------- */
    Suppliant suppliant = Suppliant();
    string* itemsName = new string[10];
    itemsName = suppliant.get_itemNames();

    /* -------------------------
        -= Set-up Store =-
    ------------------------- */
    Store store = Store();
    if (stoi(haveAccount) == 1)
    {
        string cd;
        getline(ReadFile, cd);
        store.set_currentDay(stoi(cd));

        string b;
        getline(ReadFile, b);
        store.set_balance(stod(b));

        string r;
        getline(ReadFile, r);
        store.set_rating(stod(r));

        string cn;
        getline(ReadFile, cn);
        store.set_numCustomer(stoi(cn));

        for (int i = 0; i < 10; i++)
        {
            if (i > 5)
            {
                string n;
                getline(ReadFile, n);
                const string itemName = itemsName[i];
                store.get_inventory()[itemName]->set_numItem(stoi(n));
            }
            else
            {
                string line;
                getline(ReadFile, line);
                stringstream ss1(line);
                string word;
                vector<string> information;

                while (ss1 >> word)
                    information.push_back(word);
                int expirationLength = stoi(information.at(0));
                const string itemName = itemsName[i];
                store.get_inventory()[itemName]->set_numItem(stoi(information.at(1)));
                int *expirationList = new int[expirationLength];
                for (size_t j = 2; information.size(); j++)
                {
                    expirationList[j] = stoi(information[j]);
                }
                store.get_inventory()[itemsName[i]]->set_expirationList(expirationList);
                delete[] expirationList;
            }
        }
    }
    ReadFile.close();

    double balance = store.get_balance();
    double rating = store.get_rating();
    double target = store.get_target();
    int currentDay = store.get_currentDay();
    int customerNumber = store.get_numCustomer();

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
        srand(time(nullptr));
        cout << "\n-------------------------------" << endl;
        cout << "\tWelcome to day " << currentDay << endl;
        cout << "-------------------------------\n" << endl;
        cout << "* Current Balance: $" << balance << endl;
        cout << "* Balance Target: $" << target << endl;
        cout << "-------------------------------\n" << endl;
        
        customerNumber += currentDay / 5;
        
        double *itemsCosts = new double[10];
        itemsCosts = suppliant.get_costList();
        
        cout << "-----> Buying goods for day " << currentDay << " <-----" << endl;
        suppliant.print();
        
        while (true)
        {
            int number;
            cout << "\nPlease choose items to buy (1-10) (Enter other numbers to stop purchasing): ";
            while (!(cin >> number))
            {
                cout << "Invalid input type. Please enter an integer(1-10): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (number < 1 || number > 10)
            {
                break;
            }
            number -= 1;
            int amount;
            cout << "Amount: ";
            while (!(cin >> amount))
            {
                cout << "Invalid input type. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (amount * itemsCosts[number] > balance)
            {
                cout << "Not enough money!!!" << endl;
            }
            else
            {
                string itemName = itemsName[number];
                map<string, Item *> inventory = store.get_inventory();
                for (auto i = inventory.begin(); i != inventory.end(); i++)
                {
                    if (i->first == itemName)
                    {
                        i->second->change_numItem(amount);
                        store.print();
                        balance -= suppliant.get_costList()[number] * amount;
                        cout << "\n* Remaining Balance: $" << balance << " *" << endl;
                        break;
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

        for (int i = 0; i < customerNumber; i++)
        {
            int n = rand() % currentDay + 1;
            int good = rand() % 10;

            cout << "\n----> Customer (" << i + 1 << ") want to buy \"" << n << " " << suppliant.get_itemNames()[good] << "\"" << endl;

            map<string, Item *> itemMap;
            itemMap = store.get_inventory();

            for (auto i = itemMap.begin(); i != itemMap.end(); i++)
            {
                if (i->first == itemsName[good])
                {
                    if (i->second->get_numItem() >= n)
                    {
                        balance += n * i->second->get_price();
                        i->second->change_numItem(-n);
                        i->second->sellItem(n);
                        rating += 0.3;
                        if (rating > 5)
                        {
                            rating = 5;
                        }
                    }
                    else
                    {
                        rating -= 0.5 * (n - i->second->get_numItem());
                        balance += (i->second->get_price()) * (i->second->get_numItem());
                        i->second->sellItem(-1);
                        itemMap[itemsName[good]]->set_numItem(0);
                    }
                    break;
                }
            }
            if (rating < 0)
            {
                rating = 0;
            }

            /* -------------------------
                -= Day Summary =-
            ------------------------- */
            cout << "\n=======-------- Store Status (End of Day " << store.get_currentDay() << ") --------=======\n" << endl;
            cout << "* Balance: $" << balance << endl;
            cout << "* Rating: $" << rating << endl;
            sleep(2);
        }

        cout << "\n=======-------- Final Verdict --------=======\n"
                  << endl;
        if (balance < target)
        {
            ofstream MyFile("data.txt");
            MyFile << 0;
            cout << "----> You failed to meet Day " << store.get_currentDay() << " target balance of $" << store.get_target() << "\n----> Your store faces bankruptcy!!!" << endl;
            running = false;
            MyFile.close();
        }
        else if (rating <= 0)
        {
            ofstream MyFile("data.txt");
            MyFile << 0;
            cout << "----> Your store rating reaches 0. Nobody wants to buy from you and you closed down!" << endl;
            running = false;
            MyFile.close();
        }
        else
        {
            cout << "----> Your made it through Day " << store.get_currentDay() << endl;
            cout << "\nChose one of the following option to proceed: " << endl;
            cout << "\t1. Play the next day" << endl;
            cout << "\t2. Save and exit" << endl;
            cout << "\nHow would you like to proceed (Enter 1 or 2): ";

            int choice;
            while (true)
            {
                while (!(cin >> choice) || (choice != 1 && choice != 2))
                {
                    cout << "Invalid input type. Please enter an integer (1 or 2): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (choice == 1 || choice == 2)
                {
                    break;
                }
            }
            if (choice == 2)
            {
                map<string, Item *> itemMap;
                store.updateStore();
                itemMap = store.get_inventory();
                ofstream MyFile("data.txt");
                MyFile << 1 << endl;
                MyFile << currentDay + 1 << endl;
                MyFile << balance << endl;
                MyFile << rating << endl;
                target += currentDay + 5 * (currentDay / 5);
                MyFile << customerNumber << endl;
                for (auto i = itemMap.begin(); i != itemMap.end(); i++)
                {
                    if (i->second->get_isPerishableItem() == true)
                    {
                        int n = i->second->get_shelfLifeInDay();
                        cout << n << endl;
                        int *numberOfItem = i->second->get_expirationList();
                        MyFile << n << " " << i->second->get_numItem() << " ";
                        for (int j = 0; j < n; j++)
                        {
                            MyFile << numberOfItem[j] << " ";
                        }
                    }
                    else
                    {
                        MyFile << i->second->get_numItem();
                    }
                    MyFile << "\n";
                }
                MyFile.close();
                running = false;
                cout << "Game Status Saved successfully!!!" << endl;
            }
        }
        suppliant.updateCost();
        store.updateStore();
        currentDay += 1;
        target += currentDay + 5 * (currentDay / 5);
    }
    // delete[] itemsName;

    return 0;
}
