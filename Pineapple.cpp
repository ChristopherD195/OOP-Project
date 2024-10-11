#include "Pineapple.h"
#include <iostream>

Pineapple::Pineapple():FruitOrVeg("pineapple")
{}

void Pineapple::renderTopping(){
    std::cout<<"Pineapple rendered successfully"<<std::endl;
};