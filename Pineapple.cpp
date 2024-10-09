#include "Pineapple.h"
#include <iostream>

Pineapple::Pineapple():FruitOrVeg("Pineapple")
{}

void Pineapple::renderTopping(){
    std::cout<<"Pineapple rendered successfully"<<std::endl;
};