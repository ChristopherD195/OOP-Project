#include <iostream>
#include "Customer.h"
#include "Customer1.h"
#include <stdlib.h>
#include <ctime>

int main(){
    srand(time(0));
    Customer1 bob;
    // Customer* bobby = &bob;
    bob.setBaseTip(5);
    bob.setToppingOrder();
    std::cout << bob.getBaseTip() << std::endl;

    std::vector<int> toppingOrder = bob.getToppingOrder();
    

    for (int n : toppingOrder){
        std::cout << n;
    }
    return 0;
}