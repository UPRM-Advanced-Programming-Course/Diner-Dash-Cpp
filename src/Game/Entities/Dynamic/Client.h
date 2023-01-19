#pragma once

#include "Entity.h"
#include "Burger.h"

enum ClientTypes
{
    Regular,
    Inspector
};

class Client : public Entity
{
private:
    Burger *burger;
    int originalPatience;
    int patience = 2000;

public:
    Client(int, int, int, int, ofImage, Burger *);
    ~Client();
    void tick();
    void render();
    bool serve(Burger *);
    Client *nextClient = nullptr;
    bool isLeaving = false;
    bool isServed = false;
    bool isLeavingAngry = false;
    ClientTypes clientType;
};

