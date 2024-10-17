#include "Chicken.h"
#include <iostream>

Chicken::Chicken() : Meat("chicken") {}

void Chicken::renderTopping(float angle, float distance,sf::Vector2f center){
    //disply 1 square of chicken randomly on pizza
    sf::RectangleShape chicken(sf::Vector2f(40, 35));
    chicken.setFillColor(sf::Color(255, 204, 102));
    // Set random position within pizza
    chicken.setPosition(position.x, position.y);
    std::cout<<"Chicken rendered successfully"<<std::endl;
};