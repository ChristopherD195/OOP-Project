#pragma once
#include <string>
#include "Meat.h"

class Chicken :public Meat//inherit from meat
{
private:
public:
    Chicken();
    sf::Shape* renderTopping()override;
};