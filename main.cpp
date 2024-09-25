#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>

#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"
#include "Suppliant.h"
#include "Item.h"
#include "Egg.h"
#include "Meat.h"
#include "Milk.h"

// g++ main.cpp Printable.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp Milk.cpp Meat.cpp Egg.cpp -o a
int main()
{
    std::cout << "Welcome to Retail Simulator game" << std::endl;

    bool running = true;
    std::ifstream ReadFile("data.txt");
    std::string haveAccount;
    std::getline(ReadFile, haveAccount);
    std::string i0, i1, i2, i3, i4, i5, curDay, b, r, c, t;
    Store s;

    if (haveAccount == "1")
    {
        std::getline(ReadFile, curDay);
        std::getline(ReadFile, b);
        std::getline(ReadFile, r);
        std::getline(ReadFile, c);
        std::getline(ReadFile, t);
        std::getline(ReadFile, i0);
        std::getline(ReadFile, i1);
        std::getline(ReadFile, i2);
        std::getline(ReadFile, i3);
        std::getline(ReadFile, i4);
        std::getline(ReadFile, i5);

        s = Store(std::stoi(curDay), std::stod(b), std::stod(r), std::stoi(c), std::stod(t), std::stoi(i0), std::stoi(i1), std::stoi(i2), std::stoi(i3), std::stoi(i4), std::stoi(i5));
    }
    else
    {
        s = Store();
    }
    ReadFile.close();

    double target = s.getTarget();
    int currentDay = s.getDay();
    Suppliant suppliant = Suppliant();
    int numberOfCus = s.getNumCus();
    double balance = s.getBalance();
    double rating = s.getRating();

    while (running)
    {
        std::srand(std::time(nullptr));
        std::cout << "Welcome to day " << currentDay << std::endl;
        std::cout << "Target: " << target << std::endl;

        numberOfCus += currentDay / 5;
        double *costsItems = new double[6];
        costsItems = suppliant.getCurrentCost();

        std::cout << "Buying goods for day " << currentDay << std::endl;
        std::cout << "*******************" << std::endl;

        suppliant.print();

        while (true)
        {
            std::cout << "Please choose items to buy(1-6): ";

            int n;
            std::cin >> n;

            if (n > 6 || n < 1)
            {
                break;
            }

            std::cout << "How many items do you want to buy? ";

            int amount;
            std::cin >> amount;

            if (amount * costsItems[n - 1] > balance)
            {
                std::cout << "Not enough money" << std::endl;
            }

            else
            {
                balance -= amount * costsItems[n - 1];
                s.getItems()[n - 1]->changeAmount(amount);
                std::cout << balance << std::endl;
            }
        }

        sleep(2);

        for (int i = 0; i < numberOfCus; i++)
        {
            int n = std::rand() % currentDay + 1;
            int good = std::rand() % 6;

            std::cout << "\nCustomer " << i + 1 << " want to buy " << n << " " << suppliant.getNameItems()[good] << std::endl;

            if (s.getItems()[good]->getNumberOfItems() < n)
            {
                rating -= 0.5 * (n - s.getItems()[good]->getNumberOfItems());
                balance += costsItems[good] * (s.getItems()[good]->getNumberOfItems());
                s.getItems()[good]->setNumberOfItems(0);
            }

            else
            {
                balance += n * s.getItems()[good]->getPrice();
                s.getItems()[good]->changeAmount(-n);
                rating += 0.3;

                if (rating > 5)
                {
                    rating = 5;
                }
            }

            std::cout << "Balance: " << balance << std::endl;
            std::cout << "Rating: " << rating << std::endl;

            sleep(2);
        }

        if (balance < target || rating <= 0)
        {
            std::ofstream MyFile("data.txt");
            MyFile << 0;
            std::cout << "You are lose !!!" << std::endl;
            running = false;
            MyFile.close();
        }

        else
        {
            std::cout << "Enter the number for choice: " << std::endl;
            std::cout << "1. Play the next day" << std::endl;
            std::cout << "2. Save and exit" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice != 1)
            {
                std::ofstream MyFile("data.txt");
                MyFile << 1 << std::endl;
                MyFile << currentDay + 1 << std::endl;
                MyFile << balance << std::endl;
                MyFile << rating << std::endl;
                target += currentDay + 5 * (currentDay / 5);
                MyFile << numberOfCus << std::endl;
                MyFile << target << std::endl;

                for (int i = 0; i < 6; i++)
                {
                    MyFile << s.getItems()[i]->getNumberOfItems() << std::endl;
                }

                MyFile.close();
                running = false;

                std::cout << "Saved successfully!!!" << std::endl;
            }
        }

        suppliant.updateCost();
        currentDay += 1;
        target += currentDay + 5 * (currentDay / 5);
    }

    return 0;
}