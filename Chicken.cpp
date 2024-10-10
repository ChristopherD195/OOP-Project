#include "Chicken.h"
#include <iostream>

Chicken::Chicken() : Meat("chicken") {}

void Chicken::renderTopping(){
    std::cout<<"Chicken rendered successfully"<<std::endl;
};