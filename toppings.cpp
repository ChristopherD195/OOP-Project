#include "toppings.h"

toppings::toppings()
{
    this->numToppings = 0;
}

toppings::toppings(int num, std::string type)
{
    this->numToppings = num;
    this->type = type;
}

void toppings::setNumToppings(int num){
    this->numToppings = num;
};
void toppings::setToppingType(std::string type){
    this->type = type;
}

std::string toppings::getToppingType(){
    return type;
};
int toppings::getCurrentNumToppings(){
    return numToppings;
};
