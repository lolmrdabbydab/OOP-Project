#include <iostream>
#include <fstream>
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

//g++ main.cpp Printable.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp -o a

int main(){
    std::cout<<"Welcome to Retail Simulator game"<<std::endl;
    bool running  = true;
    std::ifstream ReadFile("data.txt");
    std::string haveAccount;
    std::getline(ReadFile, haveAccount);

    Suppliant suppliant = Suppliant();
    std::string* itemsName = new std::string[10];
    itemsName = suppliant.get_itemNames();
    Store store = Store();
    if (haveAccount ==1){
        std::string cd;
        std::getline(ReadFile,cd);
        store.set_currentDay(stoi(cd));
        std::string b;
        std::getline(ReadFile,b);
        store.set_balance(stod(b));
        std::string r;
        std::getline(ReadFile,r);
        store.set_rating(stod(r));
        std::string cn;
        std::getline(ReadFile,cn);
        store.set_numCustomer(stoi(cn));
        for (int i =0;i<10;i++){
            if (i>5){
                std::string n;
                std::getline(ReadFile,n);
                store.get_inventory[itemsName[i]]->set_numItem(stoi(n));
            }
            else{
                std::string line;
                std::getline(ReadFile,line);
                std::vector<std::string> information = split_sentence(line);
                int expirationLength = stoi(information.at(0));
                store.get_inventory[itemsName[i]]->set_numItem(stoi(information.at(1)));
                int *expirationList = new int[expirationList];
                for (int j = 2;j<information.size();j++){
                    expirationList[j] = information.at(j);
                }
                store.get_inventory[itemsName[i]].set_expirationList(expirationList);
                delete []expirationList;
                
            }
        }

    }
    ReadFile.close();
    double balance = s.get_balance();
    double rating = s.get_rating();
    double target = s.get_target();
    int currentDay = s.get_currentDay();
    int customerNumber = s.get_numCustomer();

    

    while (running){
        std::srand(std::time(nullptr));
        std::cout<<"Welcome to day "<<currentDay<<std::endl;
        std::cout<<"Current Balance: "<<balance<<std::endl;
        std::cout<<"Balance Target:"<<target<<std::endl;
        customerNumber += currentDay/5;
        double* itemsCosts = new double[10];
        itemsCosts = suppliant.get_costList();
        std::cout<<"Buying goods for day "<<currentDay<<std::endl;
        std::cout<<"*******************"<<std::endl;
        suppliant.print();
        while (true){
            int number;
            std::cout<<"Please choose items to buy(1-10)(other number for stop buying): ";
            while (!(std::cin >> number)) {
                std::cout << "Invalid input type. Please enter an integer(1-10): ";
                std::cin.clear(); 
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (number<1 || number>10){
                break;
            }
            number -=1;
            int amount;
            std::cout<<"Amount: ";
            while (!(std::cin >> amount)) {
                std::cout << "Invalid input type. Please enter an integer: ";
                std::cin.clear(); 
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (amount*itemsCosts[number]>balance){
                std::cout<<"Not enough money!!!";
            }
            else{
                std::string itemName = itemsName[number];
                for (auto i = store.get_inventory().begin();i!=store.get_inventory().end();i++){
                    if (i->first==itemName){
                        i->second->change_numItem(amount);
                        store.print();
                        std::cout<<"Current Balance: "<<balance<<std::endl;
                        break;
                    } 
                }
            }


        }
        sleep(2);
        for (int i =0;i<customerNumber;i++){
            int found = 0;
            int n = std::rand()%currentDay+1;
            int good = std::rand()%10;
            std::cout<<"/nCustomer "<<i+1<<" want to buy "<<n<<suppliant.get_itemNames()[good]<<std::endl;
            std::map<string,Item*> itemMap;
            itemMap = store.get_inventory();
            for (auto i = itemMap.begin();i!=itemMap.end();i++){
                if (i->first == itemsName[good]){
                    if (i->second->get_numItem()>=n){
                        balance += n*i->second->get_price();
                        i->second->change_numItem(-n);
                        i->second->sellItem(n);
                        rating +=0.3;
                        if (rating>5){
                            rating =5;
                        }
                    }
                    else{
                        rating -= 0.5*(i->second->get_numItem());
                        balance += (i->second->get_price())*(i->second->get_numItem());
                        i->second->sellItem(-1);
                        itemMap[itemsName[good]]->set_numItem(0);
                    }
                    found = 1;
                    break;
                    }
            }
            if (found==0){
                rating -= n*0.5;
            }
            if (rating<0){
                rating =0;
            }
            std::cout<<"Balance: "<<balance<<std::endl;
            std::cout<<"Rating: "<<rating<<std::endl;
            sleep(2);
    
        }
        if (balance<target){
            std::ofstream MyFile("data.txt");
            MyFile<<0;
            std::cout<<"You can not meet the target, you are lose!!!"<<std::endl;
            running = false;
            MyFile.close();
        }
        else if (rating<=0){
            std::ofstream MyFile("data.txt");
            MyFile<<0;
            std::cout<<"Your rating is 0, you are lose!!!"<<std::endl;
            running = false;
            MyFile.close();
        }
        else{
            std::cout<<"Enter number for choice: "<<std::endl;
            std::cout<<"1. Play the next day"<<std::endl;
            std::cout<<"2. Save and exit"<<std::endl;
            int choice;
            while(true){
                while (!(std::cin >> choice)) {
                    std::cout << "Invalid input type. Please enter an integer(1-2): ";
                    std::cin.clear(); 
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                std::cin>>choice;
                if (choice ==1 || choice ==2){
                    break;
                }
            }
            if (choice ==2){
                std::map<string,Item*> itemMap;
                itemMap = store.get_inventory();
                std::ofstream MyFile("data.txt");
                MyFile<<1<<std::endl;
                MyFile<<currentDay+1<<std::endl;
                MyFile<<balance<<std::endl;
                MyFile<<rating<<std::endl;
                target += currentDay+5*(currentDay/5);
                MyFile<<customerNumber<<std::endl;
                for (auto i = itemMap.begin();i!= itemMap.end();i++){
                    if (i->second->get_isPerishableItem()){
                        int n = i->second->get_shelfLifeInDay();
                        int* numberOfItem = i->get_expirationList();
                        MyFile<<n<<" "<<i->second->get_numItem()<<" ";
                        for (int j = 0;j<n;j++){
                            MyFile<<numberOfItem[j]<<" ";
                        }
                    }
                    else{
                        MyFile<<i->second->get_numItem();
                    }
                    MyFile<<"\n";
                }
                MyFile.close();
                running = false;
                std::cout<<"Saved successfully!!!"<<std::endl;
            }
        }
        
        delete [] itemsCosts;
        suppliant.updateCost();
        store.updateStore();
        currentDay+=1;
        target += currentDay +5*(currentDay/5);
        }
    delete [] itemsName;
    return 0;
    }


