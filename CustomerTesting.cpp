#include <iostream>
#include <ctime>
#include <vector>
#include "Customer.h"
#include "Customer_a.h"

int main(){
    Customer1 bob;
    std::cout << bob.getBaseTip() << std::endl;
    bob.setBaseTip();
    std::cout << bob.getBaseTip() << std::endl;

    std::cout << bob.getNumCuts() << std::endl;
    bob.setNumCuts();
    std::cout << bob.getNumCuts() << std::endl;

    std::cout << bob.getOvenTime() << std::endl;
    bob.setOvenTime();
    std::cout << bob.getOvenTime() << std::endl;

    bob.setToppingOrder();
    std::vector<int> toppingOrder = bob.getToppingOrder();

    for (int n : toppingOrder){
        std::cout << n << " ";
    }
    std::cout << "\n";
    return 0;
}