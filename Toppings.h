#pragma once
#include <string>

class Toppings
{
private:
    std::string toppingType;
    int numTopping;
    int numToppingIncrease;
public:
    Toppings();
    Toppings(std::string toppingType);
    ~Toppings();
};