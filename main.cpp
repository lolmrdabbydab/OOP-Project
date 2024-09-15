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
    std::cout<<"Welcome to Retail Simulator game"<<std::endl;
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
    std::cout<<currentDay<<std::endl;
    Suppliant suppliant = Suppliant();
    int numberOfCus = 2;
    while (running){
        std::cout<<numberOfCus<<std::endl;
        numberOfCus+= currentDay/5;
        std::cout<<currentDay<<std::endl;
        std::cout<<numberOfCus<<std::endl;
        int balance = s.getBalance();
        double rating = s.getRating();
        double* costsItems = suppliant.getCurrentCost();
        std::cout<<"Buying goods for day "<<currentDay<<std::endl;
        std::cout<<"*******************"<<std::endl;
        suppliant.print();
        while (true){
            std::cout<<"Please choose items to buy(1-6): ";
            int n;
            std::cin>>n;
            if (n>6 || n<1){
                break;
            }
            std::cout<<"How many items do you want to buy? ";
            int amount;
            std::cin>>amount;
            if (amount * costsItems[n-1]>balance){
                std::cout<<"Not enough money"<<std::endl;
            }
            else{
                balance -=amount*costsItems[n-1];
                s.getItems()[n-1];
                std::cout<<balance<<std::endl;
            }
            

        }
        for (int i =0;i<numberOfCus;i++){
            int n = rand()%currentDay+1;
            int good = rand()%6;
            std::cout<<"Customer "<<i+1<< " want to buy " <<n<<" "<<suppliant.getNameItems()[good]<<std::endl;
            if (s.getItems()[good]->getNumberOfItems()<n){
                std::cout<<1<<std::endl;
                rating -= 0.5*(n-s.getItems()[good]->getNumberOfItems());
                std::cout<<2<<std::endl;
                balance += costsItems[good]*(s.getItems()[good]->getNumberOfItems());
                std::cout<<3<<std::endl;
                s.getItems()[good];
                //->setNumberOfItems(0);
                std::cout<<4<<std::endl;
            }
            else{
                balance += n*s.getItems()[good]->getPrice();
                s.getItems()[good]->changeAmount(-n);
                rating += 0.3 ;
                if (rating >5){
                    rating =5;
                }
            }
            std::cout<<"Balance: "<<balance<<std::endl;
            std::cout<<"Rating: "<<rating<<std::endl;
            sleep(2);
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
            std::cin>>choice;
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
                running = false;
            }
        }
        suppliant.updateCost();
        currentDay+=1;
        target += currentDay+5*(currentDay/5);

    }


    
    return 0;
}