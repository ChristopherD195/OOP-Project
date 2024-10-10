#include <iostream>
#include <ctime>
#include <vector>
#include "Customer.h"
#include "Customer1.h"

Customer1::Customer1() : Customer(){}

void Customer1::setToppingOrder(){
    toppingOrder.assign({5, 2, 1, 8, 9});
}

void Customer1::setBaseTip(){
    baseTip = 5;
}

void Customer1::setOvenTime(){
    baseTip = 30;
}

void Customer1::setNumCuts(){
    numCuts = 2;
}