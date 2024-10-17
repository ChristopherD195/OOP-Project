#include "Meat.h"
#include <iostream>

Meat::Meat(std::string toppingType) : Topping(toppingType, 1) {}

void Meat::renderTopping(float angle, float distance,sf::Vector2f center){
    std::cout<<"Meat topping"<<std::endl;
};