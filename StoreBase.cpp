#include "StoreBase.h"
#include <iostream>
#include "Item.h"
#include "Egg.h"
#include "Milk.h"
#include "Meat.h"
StoreBase::StoreBase():StoreBase(0,0,0,0,0,0){};
StoreBase::StoreBase(int i0,int i1, int i2, int i3,int i4,int i5){
    Item* cagedEgg  =new Egg(i0,true,5);
    Item* freeRangeEgg =new Egg(i1,false,8);
    Item* cowMilk = new Milk(i2,"Cow",4);
    Item* plantBasedMilk =new Milk(i3,"Almond",4);
    Item* beef =new Meat(i4,15);
    Item* chicken =new Meat(i5,10);
    items[0] = cagedEgg;
    items[1] = freeRangeEgg;
    items[2] = cowMilk;
    items[3] = plantBasedMilk;
    items[4] = beef;
    items[5] = chicken;
}
Item **StoreBase::getItems()
{
    return items;
}
void StoreBase::print()
{   
    return;
}

std::string *StoreBase::getNameItems()
{
    return nameItems;
}

StoreBase::~StoreBase()
{
    for (int i=0; i<numberOfItemtypes;i++){
        delete items[i];
    }
}
