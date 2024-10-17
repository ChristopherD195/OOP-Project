#pragma once
#include <string>
#include "Meat.h"

class Chicken :public Meat//inherit from meat
{
private:
public:
    Chicken();
    void renderTopping(float angle, float distance,sf::Vector2f center)override;
};