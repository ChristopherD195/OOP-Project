#pragma once
#include <string>

class Toppings
{
protected:
    std::string toppingType;//name of topping
    int numTopping;//number of toppings
    int numToppingIncrease;//pieces of toppings in a serve,initially set to 0
public:
    Toppings();
    Toppings(std::string toppingType);

    //set and get num of toppings
    int getNumTopping();
    void setNumTopping(int numTopping);
    
    //set and get type of topping
    std::string getToppingType();
    void setToppingType(std::string toppingType);

    //virtual function for activating sfml
    virtual void renderTopping();
};