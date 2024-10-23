#include "Pepperoni.h"
#include <iostream>

Pepperoni::Pepperoni():Meat("pepperoni")
{}

sf::Shape* Pepperoni::renderTopping(){
    sf::Shape* pepperoni = new sf::CircleShape (30);  // Radius of 30 for pepperoni
    pepperoni->setFillColor(sf::Color(255, 0, 0));
    pepperoni->setPosition(position.x, position.y);
    // std::cout<<"Pepporoni rendered successfully"<<std::endl;
    return pepperoni;
};


