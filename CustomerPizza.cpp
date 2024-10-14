#include <iostream>
#include <vector>
#include "CustomerPizza.h"
#include <cstdlib>
#include "Efficiency.h"

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

void CustomerPizza::feedback(){
    float efficiencyTemp = Efficiency.getCuttingEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Cutting: Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Cutting: Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Cutting: Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Cutting: Reaction4" << std::endl;
            break;
        case 5:
            std::cout << "Cutting: Reaction5" << std::endl;
            break;
        default:
            std::cout << "Cutting: Invalid feedback" << std::endl;
            break;
    }

    efficiencyTemp = Efficiency.getToppingsEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Toppings: Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Toppings: Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Toppings: Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Toppings: Reaction4" << std::endl;
            break;
        case 5:
            std::cout << "Toppings: Reaction5" << std::endl;
            break;
        default:
            std::cout << "Toppings: Invalid feedback" << std::endl;
            break;
    }
    
    efficiencyTemp= Efficiency.getOvenDurationEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Oven: Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Oven: Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Oven: Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Oven: Reaction4" << std::endl;
            break;
        case 4:
            std::cout << "Oven: Reaction5" << std::endl;
            break;
        default:
            std::cout << "Oven: Invalid feedback" << std::endl;
            break;
    }
}

