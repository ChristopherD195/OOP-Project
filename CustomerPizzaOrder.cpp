#include <iostream>
#include <vector>
#include "Customer.h"
#include "Customer_a.h"
#include "CustomerPizzaOrder.h"

CustomerPizza::CustomerPizza(float baseTip){
    this->numCuts = getNumCuts();
    this->baseTip = baseTip;
}