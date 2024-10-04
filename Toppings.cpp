#include "Toppings.h"
#include <iostream>
Toppings::Toppings()
{
    this->numToppingIncrease = -1;
    std::cout<<"No Topping has been added"<<std::endl;
};

Toppings::Toppings(std::string toppingType)
{
    this->toppingType = toppingType;
    this->numToppingIncrease = 0;
}

int Toppings::getNumTopping() {
    return numTopping;
};
void Toppings::setNumTopping(int numTopping){
    this->numTopping = numTopping;
};
    
std::string Toppings::getToppingType(){
    return toppingType;
};

void Toppings::setToppingType(std::string toppingType){
    this->toppingType = toppingType;
};