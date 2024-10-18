#pragma once
#include <string>
#include "Topping.h"

//this is a class for meat toppings
class Meat : public Topping
{
private:

public:
    Meat(std::string toppingType);//set num of topping in a serve to 1
    sf::Shape* renderTopping() override;
};


