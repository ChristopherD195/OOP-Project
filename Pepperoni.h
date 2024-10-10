#pragma once
#include <string>
#include "Meat.h"

class Pepperoni :public Meat//inherit from meat
{
private:
public:
    Pepperoni();
    void renderTopping()override;
};


