#include <iostream>
#include <vector>
#include "Customer.h"
#include "Customer_a.h"
#include "CustomerPizzaOrder.h"

CustomerPizza::CustomerPizza(float baseTip){
    this->baseTip = baseTip;
}

void CustomerPizza::setOvenDuration(){
    this->ovenDuration = Customer.getOvenDuration();
}

void CustomerPizza::setToppingOrder(){
    this->toppingOrder = Customer.getToppingOrder();
}

void CustomerPizza::setNumCuts(){
    this->numCuts = Customer.getNumCuts();
}