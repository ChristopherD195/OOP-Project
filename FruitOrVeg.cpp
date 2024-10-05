#include "FruitOrVeg.h"
#include <iostream>

FruitOrVeg::FruitOrVeg(std::string toppingType):Topping(toppingType,4){}


void FruitOrVeg::renderTopping(){
    std::cout<<"FruitOrVeg topping"<<std::endl;
};