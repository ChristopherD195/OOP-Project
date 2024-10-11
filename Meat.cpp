#include "Meat.h"
#include <iostream>

Meat::Meat(std::string toppingType) : Topping(toppingType, 1) {}

void Meat::renderTopping(){
    std::cout<<"Meat topping"<<std::endl;
};