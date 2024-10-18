#include "Pineapple.h"
#include <iostream>

Pineapple::Pineapple():FruitOrVeg("pineapple")
{}

sf::Shape* Pineapple::renderTopping(){
    sf::CircleShape* pineapple = new sf::CircleShape (30);  // Radius of 30 for pepperoni
    pineapple->setFillColor(sf::Color(100, 100, 0));
    pineapple->setPosition(position.x, position.y);
    std::cout<<"Pepporoni rendered successfully"<<std::endl;
    std::cout<<"Pineapple rendered successfully"<<std::endl;
    return pineapple;
};