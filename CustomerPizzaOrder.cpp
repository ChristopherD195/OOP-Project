#include <iostream>
#include <vector>
#include "Customer.h"
#include "Customer_a.h"
#include "CustomerPizzaOrder.h"

CustomerPizza::CustomerPizza(float baseTip){
    this->baseTip = baseTip;
}

void CustomerPizza::setOvenDuration(Customer& customer){
    this->ovenDuration = customer.getOvenDuration();
}

void CustomerPizza::setToppingOrder(Customer& customer){
    this->toppingOrder = customer.getToppingOrder();
}

void CustomerPizza::setNumCuts(Customer& customer){
    this->numCuts = customer.getNumCuts();
}