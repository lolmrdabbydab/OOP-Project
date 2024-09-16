#include "Suppliant.h"
#include <stdlib.h>
#include <ctime>
Suppliant::Suppliant()
{
    costs[0] = 4;
    costs[1] = 7;
    costs[2] = 3.5;
    costs[3] = 3.5;
    costs[4] = 14;
    costs[5] = 9;
    currentCosts[0] = 4;
    currentCosts[1] = 7;
    currentCosts[2] = 3.5;
    currentCosts[3] = 3.5;
    currentCosts[4] = 14;
    currentCosts[5] = 9;

}

void Suppliant::updateCost()
{
    std::srand(std::time(nullptr));
    for (int i =0;i<6;i++){
        double rateChange = 0.5+(std::rand()%10)/10.0 ;
        currentCosts[i] = costs[i] *rateChange;
    }
}

void Suppliant::print()
{
    std::cout<<"Costs of goods today"<<std::endl;
    std::cout<<"********************"<<std::endl;
    for (int i =0;i<6;i++){
        std::cout<<i+1<<". "<<nameItems[i]<<":"<<currentCosts[i]<<std::endl;
    }
}

double* Suppliant::getCurrentCost()
{
    return currentCosts;
}

Suppliant::~Suppliant()
{
}
