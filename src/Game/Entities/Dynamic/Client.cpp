#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger *burger) : Entity(x, y, width, height, sprite)
{
    this->burger = burger;
    this->clientType = ClientTypes::Regular;
}
Client::~Client()
{
    burger->~Burger();
}
void Client::render()
{
    ofSetColor(255, 255, 255);
    burger->render();

    float percent = (patience / 2000.0);
    ofSetColor(255, 255 * percent, 255 * percent);
    sprite.draw(x, y, width, height);

    ofSetColor(255, 255, 255);
    if (nextClient != nullptr)
    {
        nextClient->render();
    }
}

void Client::tick()
{
    if (!isServed)
        patience--;
    burger->setY(y);
    if (patience == 0)
    {
        isLeaving = true;
        isLeavingAngry = true;
    }
    if (nextClient != nullptr)
    {
        nextClient->tick();
    }
}

bool Client::serve(Burger *burger)
{
    if (!isServed && this->burger->isBurgerEqual(burger))
    {
        isLeaving = true;
        isServed = true;
        burger->clear();
        this->burger->clear();
        return true;
    }
    else
    {
        if (nextClient != nullptr)
        {
            return nextClient->serve(burger);
        }
    }
    return false;
}