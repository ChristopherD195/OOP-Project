#include "FruitOrVeg.h"
#include <iostream>

FruitOrVeg::FruitOrVeg(std::string toppingType):Topping(toppingType,4){}


sf::Shape* FruitOrVeg::renderTopping(){
    std::cout<<"FruitOrVeg topping"<<std::endl;
    sf::Shape* a;//incomplete
    return a;
};