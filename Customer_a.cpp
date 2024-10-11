#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "Customer.h"
#include "Customer_a.h"
//#include "Efficiency.h"


Customer1::Customer1() : Customer(){}

void Customer1::setToppingOrder(){
    toppingOrder.assign({std::rand()%3+6, 0, 0, 0});   //[pepperoni, chicken, pineapple, olive]
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

// void Customer1::feedback(){
//     float efficiencyTemp = Efficiency.getCuttingEfficiency();
//     switch (Customer.feedback_calculation(efficiencyTemp)){
//         case 1:
//             std::cout << "Cutting: Reaction1" << std::endl;
//             break;
//         case 2:
//             std::cout << "Cutting: Reaction2" << std::endl;
//             break;
//         case 3:
//             std::cout << "Cutting: Reaction3" << std::endl;
//             break;
//         case 4:
//             std::cout << "Cutting: Reaction4" << std::endl;
//             break;
//         case 5:
//             std::cout << "Cutting: Reaction5" << std::endl;
//             break;
//         default:
//             std::cout << "Cutting: Invalid feedback" << std::endl;
//             break;
//     }

//     efficiencyTemp = Efficiency.getToppingsEfficiency();
//     switch (Customer.feedback_calculation(efficiencyTemp)){
//         case 1:
//             std::cout << "Toppings: Reaction1" << std::endl;
//             break;
//         case 2:
//             std::cout << "Toppings: Reaction2" << std::endl;
//             break;
//         case 3:
//             std::cout << "Toppings: Reaction3" << std::endl;
//             break;
//         case 4:
//             std::cout << "Toppings: Reaction4" << std::endl;
//             break;
//         case 5:
//             std::cout << "Toppings: Reaction5" << std::endl;
//             break;
//         default:
//             std::cout << "Toppings: Invalid feedback" << std::endl;
//             break;
//     }
    
//     efficiencyTemp= Efficiency.getOvenDurationEfficiency();
//     switch (Customer.feedback_calculation(efficiencyTemp)){
//         case 1:
//             std::cout << "Oven: Reaction1" << std::endl;
//             break;
//         case 2:
//             std::cout << "Oven: Reaction2" << std::endl;
//             break;
//         case 3:
//             std::cout << "Oven: Reaction3" << std::endl;
//             break;
//         case 4:
//             std::cout << "Oven: Reaction4" << std::endl;
//             break;
//         case 4:
//             std::cout << "Oven: Reaction5" << std::endl;
//             break;
//         default:
//             std::cout << "Oven: Invalid feedback" << std::endl;
//             break;
//     }
// }