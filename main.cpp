#include <iostream>
#include <ctime>
#include <vector>
#include "Customer.h"
#include "Customer1.h"

int main(){
    Customer1 bob;
    bob.setBaseTip();
    bob.setToppingOrder();
    std::cout << bob.getBaseTip() << std::endl;

    std::vector<int> toppingOrder = bob.getToppingOrder();
    

    for (int n : toppingOrder){
        std::cout << n;
    }
    std::cout<< "" << std::endl;
    return 0;
}