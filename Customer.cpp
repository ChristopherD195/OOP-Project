#include <iostream>
#include <vector>
#include <ctime>
#include "Customer.h"

Customer::Customer(){
    time_t arrivalTime = time(0);
    this->waitingTime = 0;
    std::vector<int> toppingOrder;
    this->ovenTime = 0;
    this->numCuts = 0;
    this->tipRating = 0;
    this->baseTip = 0;

}

void Customer::setWaitingTime(){
    waitingTime = time(0);      //this needs to be called in player pizza
}


int Customer::feedback_calculation(float efficiency){
    if (efficiency >= 0.0f && efficiency < 0.25f) {
        return 1;
    } else if (efficiency >= 0.25f && efficiency < 0.5f) {
        return 2;
    } else if (efficiency >= 0.5f && efficiency < 0.75f) {
        return 3;
    } else if (efficiency >= 0.75f && efficiency <= 1.0f) {
        return 4;
    } else {
        std::cout << "Efficiency is out of range!" << std::endl;
    }
    return 0;
}