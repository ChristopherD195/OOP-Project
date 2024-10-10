#include <iostream>
#include <vector>
#include <ctime>

#include "Customer.h"

Customer::Customer(){
    time_t arrivalTime = time(0);
    int waitingTime = 0;
    std::vector<int> toppingOrder;
    int ovenTime = 0;
    int numCuts = 0;
    float tipRating = 0;
    float baseTip = 0;
}

void Customer::setWaitingTime(){
    waitingTime = time(0);      //this needs to be called in player pizza
}
