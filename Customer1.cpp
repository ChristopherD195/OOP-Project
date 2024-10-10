#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>

#include "Customer.h"
#include "Customer1.h"

Customer1::Customer1() : Customer(){}

void Customer1::setToppingOrder(){
    for (int i = 0; i<5; i++){
        toppingOrder.push_back(rand()%11);
    }
    std::cout << "lollll" << std::endl;
}

void Customer1::setBaseTip(){
    this->baseTip = 5;
}

void Customer1::setOvenTime(int ovenTime){
    baseTip = 30;
}

void Customer1::setNumCuts(int numCuts){
    numCuts = 2;
}