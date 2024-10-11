#include <iostream>
#include <vector>
#include <ctime>
#include "Customer.h"

Customer::Customer(){
    //time_t arrivalTime = time(0);
    //this->waitingTime = 0;
    std::vector<int> toppingOrder;
    this->ovenTime = 0;
    this->numCuts = 0;
    this->tipRating = 0;
    this->baseTip = 0;

}

void Customer::setWaitingTime(){
    waitingTime = time(0);      //this needs to be called in player pizza
}


// int Customer::feedback_calculation(float efficiency){
//     if (efficiency >= 0.0 && efficiency < 0.25) {
//         return 1;
//     } else if (efficiency >= 0.25 && efficiency < 0.5) {
//         return 2;
//     } else if (efficiency >= 0.5 && efficiency < 0.75) {
//         return 3;
//     } else if (efficiency >= 0.75 && efficiency < 1) {
//         return 4;
//     }else if (efficiency == 1) {
//         return 5;
//     } else {
//         std::cout << "Efficiency is out of range!" << std::endl;
//     }
//     return 0;
// }
