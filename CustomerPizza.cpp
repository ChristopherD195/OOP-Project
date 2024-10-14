#include <iostream>
#include <vector>
#include "CustomerPizza.h"
#include <cstdlib>

CustomerPizza::CustomerPizza(){
    srand(time(0));  //This should be in the main
    this->numCuts = 0;
    this->baseTip = 0;
    this->ovenDuration = 0;

}

void CustomerPizza::setOvenDuration(){
    this->ovenDuration = rand()%36+5;
}

void CustomerPizza::setToppingOrder(){
    toppingOrder.assign({std::rand()%3+6, std::rand()%6+2, std::rand()%4*4, std::rand()%3*4}) ;  //[pepperoni, chicken, pineapple, olive]
}

void CustomerPizza::setNumCuts(){
    this->numCuts = rand()%7+2;
}

void CustomerPizza::setOvenStartTime(){
    this->ovenStartTime = time(0);
}

int CustomerPizza::getNumCuts(){
    return numCuts;
}

float CustomerPizza::getBaseTip(){
    return baseTip;
}

int CustomerPizza::getOvenDuration(){
    return ovenDuration;
}

//Getter function to return the list of toppings (read-only access)
const std::vector<int>& CustomerPizza::getToppingOrder() const{
    return this->toppingOrder;
}



