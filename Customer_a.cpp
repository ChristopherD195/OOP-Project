#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "Customer.h"
#include "Customer_a.h"
#include "Efficiency.h"


Customer1::Customer1() : Customer(){}

void Customer1::setToppingOrder(){
    toppingOrder.assign({std::rand()%3+6, 0, 0, 0, 0});   //[pepperoni, chicken, pineapple, olive, mushroom]
}

void Customer1::setBaseTip(){
    baseTip = 5.00;
}

void Customer1::setOvenTime(){
    ovenTime = std::rand()%11+30;
}

void Customer1::setNumCuts(){
    numCuts = std::rand()%2+2;
}

void Customer1::feedback(){
    float efficiencyTemp = Efficiency.getCuttingEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Reaction4" << std::endl;
            break;
        default:
            std::cout << "Invalid feedback" << std::endl;
            break;
    }

    efficiencyTemp = Efficiency.getToppingsEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Reaction4" << std::endl;
            break;
        default:
            std::cout << "Invalid feedback" << std::endl;
            break;
    }
    
    efficiencyTemp= Efficiency.getOvenDurationEfficiency();
    switch (Customer.feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Reaction1" << std::endl;
            break;
        case 2:
            std::cout << "Reaction2" << std::endl;
            break;
        case 3:
            std::cout << "Reaction3" << std::endl;
            break;
        case 4:
            std::cout << "Reaction4" << std::endl;
            break;
        default:
            std::cout << "Invalid feedback" << std::endl;
            break;
    }
}