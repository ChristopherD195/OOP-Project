#pragma once
#include <string>
#include "FruitOrVeg.h"

class Pineapple :public FruitOrVeg//inherit from FruitOrVeg
{
private:
public:
    Pineapple();
    void renderTopping(float angle, float distance,sf::Vector2f center)override;
};