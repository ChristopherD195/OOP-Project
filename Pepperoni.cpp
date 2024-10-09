#include "Pepperoni.h"
#include <iostream>

Pepperoni::Pepperoni():Meat("pepperoni")
{}

void Pepperoni::renderTopping(){
    std::cout<<"Pepporoni rendered successfully"<<std::endl;
};


