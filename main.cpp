#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Printable.h"
#include "StoreBase.h"
#include "Store.h"
#include "Suppliant.h"
#include "Item.h"
#include "Egg.h"
#include "Meat.h"
#include "Milk.h"

int main(){
    std::cout<<"Welcome to Retail Simulator game";
    bool running  = true;
    std::ifstream ReadFile("data.txt");
    std::string haveAccount;
    std::getline(ReadFile, haveAccount);
    std::string i0,i1,i2,i3,i4,i5,curDay,balance,r;
    Store s;
    if (haveAccount=="1"){
        std::getline(ReadFile, curDay);
        std::getline(ReadFile, balance);
        std::getline(ReadFile, r);
        std::getline(ReadFile, i0);
        std::getline(ReadFile, i1);
        std::getline(ReadFile, i2);
        std::getline(ReadFile, i3);
        std::getline(ReadFile, i4);
        std::getline(ReadFile, i5);
        s = Store(std::stoi(curDay),std::stod(balance),std::stod(r),std::stoi(i0),std::stoi(i1),std::stoi(i2),std::stoi(i3),std::stoi(i4),std::stoi(i5)); 
    }
    else{
        s =Store();
    }
    ReadFile.close();
    double target=10;
    int currentDay = s.getDay();
    Suppliant suppliant;
    int numberOfCus = 2;
    while (running){
        numberOfCus+= currentDay/5;
        int balance = s.getBalance();
        double rating = s.getRating();
        double* costsItems = suppliant.getCurrentCost();
        std::cout<<"Buying goods for a new day "<<currentDay<<std::endl;
        std::cout<<"*******************"<<std::endl;
        suppliant.print();
        while (true){
            std::cout<<"Please choose items to buy(1-6): ";
            int n;
            std::cin>>n;
            if (n>6 || n<0){
                break;
            }
            std::cout<<"How many items do you want to buy? ";
            int amount;
            std::cin>>amount;
            if (amount * costsItems[n]>balance){
                std::cout<<"Not enough money"<<std::endl;
            }
            else{
                balance -=amount*costsItems[n];
                s.getItems()[n]->changeAmount(amount);
            }
            

        }
        for (int i =0;i<numberOfCus;i++){
            int n = rand()%currentDay;
            int good = rand()%6;
            std::cout<<"Customer "<<i<< " want to buy " <<n<<suppliant.getNameItems()[good];
            if (s.getItems()[good]->getNumberOfItems()*costsItems[good]<n){
                rating -= 0.5*(n-s.getItems()[good]->getNumberOfItems());
                balance += costsItems[good]*(n-s.getItems()[good]->getNumberOfItems());
                s.getItems()[good]->setNumberOfItems(0);
            }
            else{
                balance += s.getItems()[good]->getNumberOfItems()*costsItems[good];
                s.getItems()[good]->changeAmount(-n);
                rating += 0.3 ;
                if (rating >5){
                    rating =5;
                }
            }
            std::cout<<"Balance: "<<balance<<std::endl;
            std::cout<<"Rating: "<<rating<<std::endl;
            sleep(1);
        }
        if (balance<target || rating <=0){
            std::ofstream MyFile("data.txt");
            MyFile<<0;
            std::cout<<"You are lose !!!"<<std::endl;
            running = false;
            MyFile.close();
        }
        else{
            std::cout<<"Enter the number for choice: "<<std::endl;
            std::cout<<"1. Play the next day"<<std::endl;
            std::cout<<"2. Save and exit"<<std::endl;
            int choice;
            if (choice ==1){
                continue;
            }
            else{
                std::ofstream MyFile("data.txt");
                std::cout<<"Saved successfully!!!"<<std::endl;
                MyFile<<1;
                MyFile<<currentDay;
                Item** c= s.getItems();
                for (int i =0;i<6;i++){
                    MyFile<<c[i]->getNumberOfItems();
                }
                MyFile.close();
            }
        }
        currentDay+=1;
        target += currentDay+5*(currentDay/5);

    }


    
    return 0;
}