#include "Chicken.h"
#include <iostream>

Chicken::Chicken() : Meat("chicken") {}

sf::Shape* Chicken::renderTopping(){
    //disply 1 square of chicken randomly on pizza
    sf::RectangleShape* chicken = new sf::RectangleShape(sf::Vector2f(40, 35));
    chicken->setFillColor(sf::Color(255, 204, 102));
    chicken->setPosition(position.x, position.y);
    // std::cout<<"Chicken rendered successfully"<<std::endl;
    return chicken;
};