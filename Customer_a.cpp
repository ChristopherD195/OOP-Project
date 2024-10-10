#include <iostream>
#include <ctime>
#include <vector>
#include "Customer.h"
#include "Customer_a.h"

Customer1::Customer1() : Customer(){}

void Customer1::setToppingOrder(){
    toppingOrder.assign({7, 0, 0, 0, 0});   //[pepperoni, chicken, pineapple, olive, mushroom]
}

void Customer1::setBaseTip(){
    baseTip = 5.00;
}

void Customer1::setOvenTime(){
    ovenTime = 30;
}

void Customer1::setNumCuts(){
    numCuts = 2;
}