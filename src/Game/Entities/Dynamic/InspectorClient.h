#pragma once

#include "Client.h"
#include "Burger.h"

class InspectorClient : public Client
{
public:
    InspectorClient(int, int, int, int, ofImage, Burger *);
};