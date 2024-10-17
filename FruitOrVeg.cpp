#include "FruitOrVeg.h"
#include <iostream>

FruitOrVeg::FruitOrVeg(std::string toppingType):Topping(toppingType,4){}


void FruitOrVeg::renderTopping(float angle, float distance,sf::Vector2f center){
    std::cout<<"FruitOrVeg topping"<<std::endl;
};