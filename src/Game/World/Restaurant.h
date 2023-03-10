//
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"

class Restaurant
{
private:
    Player *player;
    EntityManager *entityManager;
    int ticks = 0;
    std::vector<ofImage> people;
    int money = 0;
    int angryClientCount = 0;

public:
    Restaurant();
    Player *getPlayer();
    void setPlayer(Player *player);
    Item *cheese;
    Item *lettuce;
    Item *tomato;
    Item *burger;
    Item *botBread;
    Item *topBread;
    ofImage floor;
    ofImage table;
    ofImage chair1;
    ofImage chair2;
    void initItems();
    void initCounters();
    void initClients();
    void initDecorations();
    void generateClient();
    void serveClient();
    void tick();
    void render();
    void keyPressed(int key);
    int getMoney();
    int getAngryClientCount();
    void reset();
};

#endif //APGAMEENGINE_RESTAURANT_H
