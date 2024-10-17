#include "Pepperoni.h"
#include <iostream>

Pepperoni::Pepperoni():Meat("pepperoni")
{}

void Pepperoni::renderTopping(float angle, float distance,sf::Vector2f center){
    sf::CircleShape pepperoni(30);  // Radius of 30 for pepperoni
    pepperoni.setFillColor(sf::Color(255, 0, 0));
    // Set random position within pizza
    float x = center.x + distance * std::cos(angle);
    float y = center.y + distance * std::sin(angle);
    pepperoni.setPosition(x, y);
    std::cout<<"Pepporoni rendered successfully"<<std::endl;
};


