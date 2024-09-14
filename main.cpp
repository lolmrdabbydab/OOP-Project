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
    std::ofstream MyFile("data.txt");
    int haveAccount;
    std::getline(MyFile, haveAccount);
    if (haveAccount){
        Store s = Store(std::stoi(std::getline(MyFile, haveAccount)),std::stod(std::getline(MyFile, haveAccount)),std::stod(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)),std::stoi(std::getline(MyFile, haveAccount)));
    }
    else{
        Store s;
    }
    double target;
    while (running){
    }



    return 0;
}