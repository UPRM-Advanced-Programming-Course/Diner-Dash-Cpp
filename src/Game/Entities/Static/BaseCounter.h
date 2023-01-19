//
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_BASECOUNTER_H
#define APGAMEENGINE_BASECOUNTER_H
#include "Item.h"
#include "Entity.h"

enum CounterTypes
{
    RegularCounter,
    Stove
};

class BaseCounter : public Entity
{
private:
    Item *item;

public:
    BaseCounter(int x, int y, int width, int height, Item *item, ofImage sprite);
    CounterTypes counterType;
    Item *getItem();
    void showItem();
    CounterTypes getCounterType();
};
#endif //APGAMEENGINE_BASECOUNTER_H
