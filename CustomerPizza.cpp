#include <iostream>
#include <vector>
#include "CustomerPizza.h"
#include <cstdlib>

CustomerPizza::CustomerPizza(){
    srand(time(0));
    this->numCuts = 0;
    this->baseTip = 0;
    this->ovenDuration = 0;

}

void CustomerPizza::updateOvenDuration(){
    this->ovenDuration = rand()%26+5;
}

void CustomerPizza::updateToppingOrder(){
    toppingOrder.assign({std::rand()%3+6, std::rand()%6+2, std::rand()%4*4, std::rand()%3*4}) ;  //[pepperoni, chicken, pineapple, olive]
}

void CustomerPizza::updateNumCuts(){
    this->numCuts = rand()%7+2;
}

void CustomerPizza::setOvenStartTime(){
    
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
std::vector<int>& CustomerPizza::getToppingOrder() {
    return this->toppingOrder;
}

void CustomerPizza::setNumCuts(int numCuts){
    this->numCuts = numCuts;
};
void CustomerPizza::setBaseTip(float baseTip){
    this->baseTip = baseTip;
};
void CustomerPizza::setToppingOrder(std::vector<int> toppingOrder){
    this->toppingOrder = toppingOrder;
};
void CustomerPizza::setOvenDuration(int ovenDuration){
    this->ovenDuration = ovenDuration;
};


int CustomerPizza::feedback_calculation(float efficiency){
    if (efficiency >= 0.0 && efficiency < 0.25) {
        return 1;
    } else if (efficiency >= 0.25 && efficiency < 0.5) {
        return 2;
    } else if (efficiency >= 0.5 && efficiency < 0.75) {
        return 3;
    } else if (efficiency >= 0.75 && efficiency < 1) {
        return 4;
    }else if (efficiency == 1) {
        return 5;
    } else {
        std::cout << "Efficiency is out of range! (Invalid input)" << std::endl;
    }
    return 0;
}

void CustomerPizza::reaction(Efficiency){
    float efficiencyTemp = Efficiency.getCuttingEfficiency();
    switch (feedback_calculation(efficiencyTemp)){
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
    switch (feedback_calculation(efficiencyTemp)){
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
    switch (feedback_calculation(efficiencyTemp)){
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

