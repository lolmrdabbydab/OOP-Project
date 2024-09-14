#include "StoreBase.h"
#include <iostream>

StoreBase::StoreBase()StoreBase(0,0,0,0,0,0){};
StoreBase::StoreBase(int i0,int i1, int i2, int i3,int i4,int i5){
    numberOfItemtypes = 6;
    items = new Item*[numberOfItemtypes];
    Item* cagedEgg  =Egg(5,true,i0);
    Item*   freeRangeEgg = Egg(8,false,i1);
    Item* cowMilk = Milk(4,"Cow",i2);
    Item* plantBasedMilk = Milk(4,"Almond",i3);
    Item* beef = Meat(15,i4);
    Item* chicken = Meat(10,i5);
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

StoreBase::~StoreBase()
{
    for (int i=0; i<numberOfItemtypes;i++){
        delete items[i];
    }
    delete []items
}
