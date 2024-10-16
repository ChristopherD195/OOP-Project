#pragma once
#include <string>
#include "Topping.h"

//this is a class for FruitOrVeg toppings
class FruitOrVeg : public Topping
{
private:

public:
    FruitOrVeg(std::string toppingType);//set num of topping in a serve to 4
    void renderTopping()override;
};