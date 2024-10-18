#include "Topping.h"
#include <iostream>
Topping::Topping(): toppingType(""), numTopping(0), numToppingIncrease(0), isRendered(false) {
    // Default constructor body
    std::cout<<"No Topping has been added"<<std::endl;
};
    

Topping::Topping(std::string toppingType, int numToppingIncrease)
{
    this->toppingType = toppingType;
    this->numToppingIncrease = numToppingIncrease;
    this->isRendered = 0;
    // Random generator for topping positions
    this->position.x = 400 + (rand() %  280) * std::cos((float)(rand() % 62) / 10.f);
    this->position.y = 400 + (rand() %  280) * std::sin((float) (rand() % 62) / 10.f);//may change!!
    
}

int Topping::getNumTopping() {
    return numTopping;
};
void Topping::setNumTopping(int numTopping){
    this->numTopping = numTopping;
};

int Topping::getNumToppingIncrease() {
    return numToppingIncrease;
};
void Topping::setNumToppingIncrease(int numToppingIncrease){
    this->numToppingIncrease = numToppingIncrease;
};
    
std::string Topping::getToppingType(){
    return toppingType;
};

void Topping::setToppingType(std::string toppingType){
    this->toppingType = toppingType;
};

Topping::~Topping() {}