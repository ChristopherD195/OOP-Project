#include "Olive.h"
#include <iostream>

Olive::Olive() : FruitOrVeg("olive") {}

void Olive::renderTopping(float angle, float distance,sf::Vector2f center){
    std::cout<<"Olive rendered successfully"<<std::endl;
};