//
// Created by joshu on 11/4/2020.
//
#include "Item.h"
#include "Burger.h"

Burger::Burger(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item)
{
    ingredients.push(item);

    if (item->name == "cheese")
        this->cheese++;
    if (item->name == "lettuce")
        this->lettuce++;
    if (item->name == "tomato")
        this->tomato++;
    if (item->name == "patty")
        this->burger++;
    if (item->name == "bottomBun")
        this->bottombun++;
    if (item->name == "topBun")
        this->topbun++;
}

void Burger::render()
{
    int counter = 1;

    stack<Item *> tempStack;

    while (!ingredients.empty())
    {
        tempStack.push(ingredients.top());
        ingredients.pop();
    };

    while (!tempStack.empty())
    {
        Item *ingredient = tempStack.top();
        ingredient->sprite.draw(x, y - (counter++ * 10), width, height);
        ingredients.push(ingredient);
        tempStack.pop();
    };
}

void Burger::removeLastIngredient()
{
    if (!ingredients.empty())
    {
        Item *item;
        item = ingredients.top();
        ingredients.pop();

        if (item->name == "cheese")
            this->cheese--;
        if (item->name == "lettuce")
            this->lettuce--;
        if (item->name == "tomato")
            this->tomato--;
        if (item->name == "patty")
            this->burger--;
        if (item->name == "bottomBun")
            this->bottombun--;
        if (item->name == "topBun")
            this->topbun--;
    }
}

void Burger::clear()
{
    while (!ingredients.empty())
        ingredients.pop();
    this->cheese = 0;
    this->lettuce = 0;
    this->tomato = 0;
    this->burger = 0;
    this->bottombun = 0;
    this->topbun = 0;
}

bool Burger::isBurgerEqual(Burger *burger)
{
    if (ingredients.size() != burger->ingredients.size())
        return false;

    return (
        topbun == burger->topbun &&
        bottombun == burger->bottombun &&
        lettuce == burger->lettuce &&
        tomato == burger->tomato &&
        this->burger == burger->burger &&
        cheese == burger->cheese);
}