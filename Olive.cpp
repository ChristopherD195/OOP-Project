#include "Olive.h"
#include <iostream>

Olive::Olive() : FruitOrVeg("olive") {}

sf::Shape* Olive::renderTopping(){
    sf::Shape* olive = new EllipseShape(sf::Vector2f(10,5));
    //set initial size of olive
    olive->setFillColor(sf::Color(102,0,51,100));
    olive->setOutlineThickness(10);
    olive->setOutlineColor(sf::Color(102,0,51));
    olive->setPosition(position.x,position.y);
    return olive;
};