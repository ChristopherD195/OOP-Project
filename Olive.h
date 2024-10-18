#pragma once
#include <string>
#include "FruitOrVeg.h"
#include "EllipseShape.h"

class Olive :public FruitOrVeg//inherit from FruitOrVeg
{
private:
public:
    Olive();
    sf::Shape* renderTopping()override;
};