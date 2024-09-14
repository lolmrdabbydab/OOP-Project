#include "Suppliant.h"
#include <stdlib.h>
Suppliant::Suppliant()
{
    costs[0] = 4;
    costs[1] = 7;
    costs[2] = 3.5;
    costs[3] = 3.5;
    costs[4] = 14;
    costs[5] = 9;

}

void Suppliant::updateCost()
{
    for (int i =0;i<6;i++){
        double rateChange = 0.5+(rand()%10)/10 ;
        currentCosts[i] = costs[i] *rateChange;
    }
}

void Suppliant::print()
{
    std::cout<<"Costs of goods today"<<std::endl;
    std::cout<<"********************"<<std::endl;
    for (int i =0;i<6;i++){
        std::cout<<i<<". "<<nameItems[i]<<":"<<currentCosts<<std::endl;
    }
}

double* Suppliant::getCurrentCost()
{
    return currentCosts;
}

Suppliant::~Suppliant()
{
}
