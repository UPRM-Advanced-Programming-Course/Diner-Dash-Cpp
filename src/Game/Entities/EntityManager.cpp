#include "EntityManager.h"

int EntityManager::leavingAngryCount()
{
    int angryLeavingCount = 0;
    Client *tempClient = firstClient;
    while (tempClient != nullptr && tempClient->isLeaving)
    {
        if (tempClient->isLeavingAngry)
        {
            angryLeavingCount++;
        }
        tempClient = tempClient->nextClient;
    }
    return angryLeavingCount;
}

int EntityManager::leavingInspectorsCount()
{
    int inspectorLeaving = 0;
    Client *tempClient = firstClient;
    while (tempClient != nullptr && tempClient->isLeaving)
    {
        if (tempClient->isLeavingAngry && tempClient->clientType == ClientTypes::Inspector)
        {
            inspectorLeaving++;
        }
        tempClient = tempClient->nextClient;
    }
    return inspectorLeaving;
}

void EntityManager::tick()
{
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->tick();
    }
    if (firstClient != nullptr)
    {
        firstClient->tick();
    }
}

void EntityManager::removeLeavingClients()
{
    Client *tempClient = nullptr;
    while (firstClient != nullptr && firstClient->isLeaving)
    {
        tempClient = firstClient->nextClient;
        delete firstClient;
        firstClient = tempClient;
    }
}

void EntityManager::render()
{
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->render();
    }
    if (firstClient != nullptr)
    {
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e)
{
    entities.push_back(e);
}

void EntityManager::addClient(Client *c)
{
    if (firstClient == nullptr)
    {
        firstClient = c;
    }
    else
    {
        Client *tempClient = firstClient;
        tempClient->setY(tempClient->getY() + 72);
        while (tempClient->nextClient != nullptr)
        {
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY() + 72);
        }
        tempClient->nextClient = c;
    }
}

void EntityManager::resetClients() {
    stack<Client *> clients;
    Client * tempClient = firstClient;

    while(tempClient != nullptr) {
        clients.push(tempClient);
        tempClient = tempClient->nextClient;
    };

    while(!clients.empty()) {
        Client* curr = clients.top();
        clients.pop();
        delete curr;
    };

    this->firstClient = nullptr;
}