#pragma once
#include <string>
#include "FruitOrVeg.h"

class Pineapple :public FruitOrVeg//inherit from FruitOrVeg
{
private:
public:
    Pineapple();
    void renderTopping()override;
};