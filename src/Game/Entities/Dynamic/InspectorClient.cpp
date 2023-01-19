#include "InspectorClient.h"

InspectorClient::InspectorClient(int x, int y, int width, int height, ofImage sprite, Burger *burger) : Client(x, y, width, height, sprite, burger)
{
    clientType = ClientTypes::Inspector;
}