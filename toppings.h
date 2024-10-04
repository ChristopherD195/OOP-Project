#pragma once
#include<string>

class toppings
{
protected:
    int numToppings;
    std:: string type;
public:
    toppings();
    toppings(int num, std::string type);
    void setNumToppings(int num);
    void setToppingType(std::string type);
    std::string getToppingType();
    int getCurrentNumToppings();
    virtual void render() = 0;//render visuals

};


