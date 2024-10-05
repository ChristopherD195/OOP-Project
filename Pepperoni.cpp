#include "Pepperoni.h"
#include <iostream>

Pepperoni::Pepperoni():Meat("Pepperoni")
{}

void Pepperoni::renderTopping(){
    std::cout<<"Pepporoni rendered successfully"<<std::endl;
};


