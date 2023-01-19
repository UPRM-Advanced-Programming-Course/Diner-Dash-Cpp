//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer()
{
    return player;
}

void Restaurant::setPlayer(Player *player)
{
    this->player = player;
}

Restaurant::Restaurant()
{
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);
    initItems();
    initCounters();
    initClients();
    initDecorations();
    //generateClient();
}
void Restaurant::initItems()
{
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43);   // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48);    // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39);   // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41);   // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34);   // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51);    // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}

int Restaurant::getMoney()
{
    return money;
}

int Restaurant::getAngryClientCount()
{
    return angryClientCount;
}

void Restaurant::initCounters()
{
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224, 12, 32, 43);  //stoveTop
    lettuceCounterImg.cropFrom(counterSheet, 96, 76, 32, 43); //Vegetables
    emptyCounterImg.cropFrom(counterSheet, 0, 245, 30, 43);   //Empty
    tomatoCounterImg.cropFrom(counterSheet, 96, 200, 32, 48); //fruit basket
    cheeseCounterImg.cropFrom(counterSheet, 64, 73, 32, 46);  //cheese
    plateCounterImg.cropFrom(counterSheet, 0, 133, 32, 50);   //plates
    breadCounterImg.cropFrom(counterSheet, 0, 63, 34, 56);    //buns
    entityManager->addEntity(new BaseCounter(0, yOffset - 16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth, yOffset - 7, counterWidth, 108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth * 2, yOffset, counterWidth, 102, burger, stoveCounterImg, 200));
    entityManager->addEntity(new BaseCounter(counterWidth * 3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 4, yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 5, yOffset - 10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 6, yOffset - 32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 7, yOffset - 32, counterWidth, 133, topBread, breadCounterImg));
}
void Restaurant::initClients()
{
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
}

void Restaurant::initDecorations()
{
    ofImage decorationSheet;
    decorationSheet.load("images/sprite.png");
    table.cropFrom(decorationSheet, 20, 28, 64, 52);
    chair1.cropFrom(decorationSheet, 108, 14, 32, 37);
    chair2.cropFrom(decorationSheet, 108, 52, 32, 37);
}

void Restaurant::tick()
{
    ticks++;
    if (ticks % 400 == 0)
    {
        generateClient();
    }
    player->tick();
    entityManager->tick();

    angryClientCount += entityManager->leavingAngryCount();
    int inspectorCount = entityManager->leavingInspectorsCount();
    for (int i = 0; i < inspectorCount; i++)
    {
        money /= 2;
    }

    entityManager->removeLeavingClients();
}

void Restaurant::generateClient()
{
    Burger *b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for (int i = 0; i < 3; i++)
    {
        int ingredient = ofRandom(1, 4);

        switch (ingredient)
        {
        case 1:
            b->addIngredient(burger);
            break;
        case 2:
            b->addIngredient(cheese);
            break;
        case 3:
            b->addIngredient(tomato);
            break;
        case 4:
            b->addIngredient(lettuce);
            break;
        }
    }
    b->addIngredient(topBread);

    int clientNum = ofRandom(8);
    if (clientNum == 7)
    {
        entityManager->addClient(new InspectorClient(0, 50, 64, 72, people[clientNum], b));
    }
    else
    {
        entityManager->addClient(new Client(0, 50, 64, 72, people[clientNum], b));
    }
}

void Restaurant::render()
{
    floor.draw(0, 0, ofGetWidth(), ofGetHeight());

    table.draw(410, 20);
    chair1.draw(378,27.5);
    chair2.draw(474,27.5);
    table.draw(410, 166);
    chair2.draw(378,173.5);
    chair1.draw(474,173.5);
    table.draw(410, 312);
    chair1.draw(378,319.5);
    chair2.draw(474,319.5);

    //draw chairs

    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth() / 2 - 60, 10);
    ofDrawBitmapString("Clients Left: " + to_string(angryClientCount), ofGetWidth() / 2 + 40, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient()
{
    if (entityManager->firstClient != nullptr)
    {
        if (entityManager->firstClient->serve(player->getBurger()))
        {
            money += 10;
        }
    }
}

void Restaurant::keyPressed(int key)
{
    player->keyPressed(key);
    if (key == 's')
    {
        serveClient();
    }
}

void Restaurant::reset()
{
    money = 0;
    angryClientCount = 0;
    ticks = 0;

    player->setX(0);
    player->getBurger()->clear();

    entityManager->resetClients();
    generateClient();
}
