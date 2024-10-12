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

// g++ --std=c++11 main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp -o a
// clang++ --std=c++11 main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp -o a

int main()
{
    system("clear");

    /* -------------------------
        -= Get Data File =-
    ------------------------- */
    std::ifstream ReadFile("data.txt");
    std::string haveAccount;
    std::getline(ReadFile, haveAccount);

    /* -------------------------
        -= Set-up Suppliant =-
    ------------------------- */
    Suppliant suppliant = Suppliant();
    std::string *itemsName = new std::string[10];
    itemsName = suppliant.get_itemNames();

    /* -------------------------
        -= Set-up Store =-
    ------------------------- */
    Store store = Store();
    if (stoi(haveAccount) == 1)
    {
        std::string cd;
        std::getline(ReadFile, cd);
        store.set_currentDay(stoi(cd));

        std::string b;
        std::getline(ReadFile, b);
        store.set_balance(stod(b));

        std::string r;
        std::getline(ReadFile, r);
        store.set_rating(stod(r));

        std::string cn;
        std::getline(ReadFile, cn);
        store.set_numCustomer(stoi(cn));

        for (int i = 0; i < 10; i++)
        {
            if (i > 5)
            {
                std::string n;
                std::getline(ReadFile, n);
                const std::string itemName = itemsName[i];
                store.get_inventory()[itemName]->set_numItem(stoi(n));
            }
            else
            {
                std::string line;
                std::getline(ReadFile, line);
                std::stringstream ss1(line);
                std::string word;
                vector<string> information;

                while (ss1 >> word)
                    information.push_back(word);
                int expirationLength = stoi(information.at(0));
                const std::string itemName = itemsName[i];
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
    std::cout << "-= Welcome to The Retail Simulator Game =-" << std::endl;
    // Introduction Prompt

    /* -------------------------
    -= User Store Purchasing =-
    ------------------------- */
    bool running = true;
    while (running)
    {
        std::srand(std::time(nullptr));
        std::cout << "\n-------------------------------" << std::endl;
        std::cout << "\tWelcome to day " << currentDay << std::endl;
        std::cout << "-------------------------------\n" << std::endl;
        std::cout << "* Current Balance: $" << balance << std::endl;
        std::cout << "* Balance Target: $" << target << std::endl;
        std::cout << "-------------------------------\n" << std::endl;
        
        customerNumber += currentDay / 5;
        
        double *itemsCosts = new double[10];
        itemsCosts = suppliant.get_costList();
        
        std::cout << "-----> Buying goods for day " << currentDay << " <-----" << std::endl;
        std::cout << "************************************" << std::endl;
        suppliant.print();
        
        while (true)
        {
            int number;
            std::cout << "\nPlease choose items to buy (1-10) (Enter other numbers to stop purchasing): ";
            while (!(std::cin >> number))
            {
                std::cout << "Invalid input type. Please enter an integer(1-10): ";
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (number < 1 || number > 10)
            {
                break;
            }
            number -= 1;
            int amount;
            std::cout << "Amount: ";
            while (!(std::cin >> amount))
            {
                std::cout << "Invalid input type. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (amount * itemsCosts[number] > balance)
            {
                std::cout << "Not enough money!!!" << std::endl;
            }
            else
            {
                std::string itemName = itemsName[number];
                std::map<std::string, Item *> inventory = store.get_inventory();
                for (auto i = inventory.begin(); i != inventory.end(); i++)
                {
                    if (i->first == itemName)
                    {
                        i->second->change_numItem(amount);
                        store.print();
                        balance -= suppliant.get_costList()[number] * amount;
                        std::cout << "\n* Remaining Balance: $" << balance << " *" << std::endl;
                        break;
                    }
                }
            }
        }

        /* -------------------------
                -= Run Day =-
        ------------------------- */

        sleep(1);

        std::cout << "\n========--------- " << "Simulating Day " << store.get_currentDay() << " ---------========" << std::endl;

        sleep(2);

        for (int i = 0; i < customerNumber; i++)
        {
            int n = std::rand() % currentDay + 1;
            int good = std::rand() % 10;

            std::cout << "\n----> Customer (" << i + 1 << ") want to buy \"" << n << " " << suppliant.get_itemNames()[good] << "\"" << std::endl;

            std::map<string, Item *> itemMap;
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
            std::cout << "\n=======-------- Store Status (End of Day " << store.get_currentDay() << ") --------=======\n" << endl;
            std::cout << "* Balance: $" << balance << std::endl;
            std::cout << "* Rating: $" << rating << std::endl;
            sleep(2);
        }

        std::cout << "\n=======-------- Final Verdict --------=======\n"
                  << endl;
        if (balance < target)
        {
            std::ofstream MyFile("data.txt");
            MyFile << 0;
            std::cout << "----> You failed to meet Day " << store.get_currentDay() << " target balance of $" << store.get_target() << "\n----> Your store faces bankruptcy!!!" << std::endl;
            running = false;
            MyFile.close();
        }
        else if (rating <= 0)
        {
            std::ofstream MyFile("data.txt");
            MyFile << 0;
            std::cout << "----> Your store rating reaches 0. Nobody wants to buy from you and you closed down!" << std::endl;
            running = false;
            MyFile.close();
        }
        else
        {
            std::cout << "----> Your made it through Day " << store.get_currentDay() << "\n\nChose one of the following option to proceed: " << std::endl;
            std::cout << "1. Play the next day" << std::endl;
            std::cout << "2. Save and exit" << std::endl;
            std::cout << "\nHow would you like to proceed (Enter 1 or 2): ";

            int choice;
            while (true)
            {
                while (!(std::cin >> choice) || (choice != 1 && choice != 2))
                {
                    std::cout << "Invalid input type. Please enter an integer (1 or 2): ";
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (choice == 1 || choice == 2)
                {
                    break;
                }
            }
            if (choice == 2)
            {
                std::map<string, Item *> itemMap;
                store.updateStore();
                itemMap = store.get_inventory();
                std::ofstream MyFile("data.txt");
                MyFile << 1 << std::endl;
                MyFile << currentDay + 1 << std::endl;
                MyFile << balance << std::endl;
                MyFile << rating << std::endl;
                target += currentDay + 5 * (currentDay / 5);
                MyFile << customerNumber << std::endl;
                for (auto i = itemMap.begin(); i != itemMap.end(); i++)
                {
                    if (i->second->get_isPerishableItem() == true)
                    {
                        int n = i->second->get_shelfLifeInDay();
                        std::cout << n << std::endl;
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
                std::cout << "Game Status Saved successfully!!!" << std::endl;
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
