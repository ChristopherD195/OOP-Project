#include "Pineapple.h"
#include <iostream>

Pineapple::Pineapple():FruitOrVeg("pineapple")
{}

void Pineapple::renderTopping(float angle, float distance,sf::Vector2f center){
    std::cout<<"Pineapple rendered successfully"<<std::endl;
};