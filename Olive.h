#pragma once
#include <string>
#include "FruitOrVeg.h"

class Olive :public FruitOrVeg//inherit from FruitOrVeg
{
private:
public:
    Olive();
    void renderTopping()override;
};