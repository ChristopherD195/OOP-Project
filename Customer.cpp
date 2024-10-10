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
