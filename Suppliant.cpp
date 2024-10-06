#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <ctime>

#include "Printable.h"
#include "StoreBase.h"
#include "Suppliant.h"

using namespace std;

// Constructors

Suppliant::Suppliant() {
    this->costRefList[0] = 5;
    this->costRefList[1] = 5.5;
    this->costRefList[2] = 4;
    this->costRefList[3] = 4;
    this->costRefList[4] = 8;
    this->costRefList[5] = 12;
    this->costRefList[6] = 7;
    this->costRefList[7] = 7;
    this->costRefList[8] = 10;
    this->costRefList[9] = 11;
    for (int i =0;i<10;i++){
        costList[i] = costRefList[i];
    }

}
    

// Getters
double* Suppliant::get_costRefList()  { return  costRefList; }
double* Suppliant::get_costList()  { return  costList; }



// Setters
void Suppliant::set_costRefList(double[10])
{
}

void Suppliant::set_costList(double[10])
{
}

// Methods
void Suppliant::print() {
    std::cout<<"Costs of goods today"<<std::endl;
    std::cout<<"********************"<<std::endl;
    for (int i =0;i<10;i++){
        std::cout<<i+1<<". "<<itemNames[i]<<":"<<costList[i]<<std::endl;
    }
}

void Suppliant::updateCost()
{
    std::srand(std::time(nullptr));
    for (int i =0;i<10;i++){
        double rateChange = 0.5+(std::rand()%10)/10.0 ;
        costList[i] = costRefList[i] *rateChange;
    }
    
}

// Destructor
Suppliant::~Suppliant() {
}