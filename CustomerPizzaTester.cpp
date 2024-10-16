#include <iostream>
#include "CustomerPizza.h"
#include "Pizza.h"
#include "Topping.h"
#include "Efficiency.h"
#include "state.h"
#include <vector>
#include <ctime>

//This will test the assigning of values to the customerPizza, thus determining what the customer will order

int main(){
    srand(time(0));     //Randomise the seed each time for random generation
    CustomerPizza customer;
    PlayerPizza pizza;
    std::cout << "Testing random generation for the order" << std::endl;

    //No set values to test/compare between, however running the program multiple times and seeing random numbers being generated each time will be sufficient testing
    customer.updateBaseTip();
    std::cout << "Random base tip: " << customer.getBaseTip() << std::endl;

    customer.updateNumCuts();
    std::cout << "Random number of cuts: " << customer.getNumCuts() << std::endl;

    customer.updateOvenDuration();
    std::cout << "Random Oven Duration: " << customer.getOvenDuration() << std::endl;

    customer.updateToppingOrder();
    std::vector<int> toppingOrder = customer.getToppingOrder();

    std::cout << "Pepperoni: " << toppingOrder[0] << std::endl;
    std::cout << "Chicken: " << toppingOrder[1] << std::endl;
    std::cout << "Pineapple: " << toppingOrder[2] << std::endl;
    std::cout << "Olive: " << toppingOrder[3] << std::endl;

    //To make the testing about the customer class functions only, the arguments for the set functions will be determined. This allows for easier testing as well

    std::cout << "Testing using a save file for the order" << std::endl;
    std::cout << "Expecting: base tip: 3  Number of cuts: 4  Oven Duration: 30" << std::endl;
    std::cout << "Topping Order: Pepperoni: 1  Chicken: 2  Pineapple: 3  Olive: 4" << std::endl;

    //The Output before and after this comment should be the same, and thus the functions and easily be tested for functionality
    std::cout << "Output" << std::endl;
    customer.setBaseTip(3);
    std::cout << "Basetip: " << customer.getBaseTip();

    customer.setNumCuts(4);
    std::cout << "  Number of Cuts: " << customer.getNumCuts();

    customer.setOvenDuration(30);
    std::cout << "  Oven Duration: " << customer.getOvenDuration() <<std::endl;

    std::cout << "Toppings: " <<std::endl;
    customer.setToppingOrder({1, 2, 3, 4});
    std::vector<int> toppingOrders = customer.getToppingOrder();

    std::cout << "Pepperoni: " << toppingOrders[0];
    std::cout << "  Chicken: " << toppingOrders[1];
    std::cout << "  Pineapple: " << toppingOrders[2];
    std::cout << "  Olive: " << toppingOrders[3] << std::endl;

    return 0;
}