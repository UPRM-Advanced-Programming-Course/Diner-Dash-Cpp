//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H

#include "Item.h"
#include "Entity.h"

class Burger
{
private:
    int x, y, width, height;
    stack<Item *> ingredients;
    int topbun = 0;
    int bottombun = 0;
    int lettuce = 0;
    int tomato = 0;
    int burger = 0;
    int cheese = 0;

public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeLastIngredient();
    void render();
    void clear();
    void setY(int y)
    {
        this->y = y;
    }

    bool isBurgerEqual(Burger *);
};

#endif //APGAMEENGINE_BURGER_H
