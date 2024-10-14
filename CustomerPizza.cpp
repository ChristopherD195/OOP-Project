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

void CustomerPizza::reaction(Efficiency rating){
    float efficiencyTemp = rating.getToppingsEfficiency();
    switch (feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Garbage on pizza? Save it for yourself!" << std::endl;
            break;
        case 2:
            std::cout << "Seems like someone tried really hard? Mhm, not enough." << std::endl;
            break;
        case 3:
            std::cout << "Oh lala! Mamma Mia! Perfecto:3" << std::endl;
            break;
        case 4:
            std::cout << "Master Topping Spreader!" << std::endl;
            break;
        case 5:
            std::cout << "Molto Bene! Bellisimo :D" << std::endl;
            break;
        default:
            std::cout << "Toppings: Invalid feedback" << std::endl;
            break;
    }
    
    efficiencyTemp= rating.getOvenDurationEfficiency();
    switch (feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "Ergh! Raw/Burned pizza? I am reporting you to Food Safety!" << std::endl;
            break;
        case 2:
            std::cout << "Meh. Too bad. Not visiting again." << std::endl;
            break;
        case 3:
            std::cout << "(sniff sniff)Smells good!" << std::endl;
            break;
        case 4:
            std::cout << "You have a baking brain:C" << std::endl;
            break;
        case 5:
            std::cout << "This is my dream baked pizza! QwQ" << std::endl;
            break;
        default:
            std::cout << "Oven: Invalid feedback" << std::endl;
            break;
    }

    efficiencyTemp = rating.getCuttingEfficiency();
    switch (feedback_calculation(efficiencyTemp)){
        case 1:
            std::cout << "GG! C'est terrible!!!! :<" << std::endl;
            break;
        case 2:
            std::cout << "I wish you could cut your head off!" << std::endl;
            break;
        case 3:
            std::cout << "Hmm. Decent cutting. Have you worked at Costco?" << std::endl;
            break;
        case 4:
            std::cout << "Fei Chang Hao! Tres bien, love it." << std::endl;
            break;
        case 5:
            std::cout << "You are an ancienct Greek God of Pizza cutting techniques!" << std::endl;
            break;
        default:
            std::cout << "Cutting: Invalid feedback" << std::endl;
            break;
    }
}

