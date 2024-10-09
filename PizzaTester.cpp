#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>

int main() {
    Pizza pizza;
    bool toppingExists = false;
    while (toppingExists == 0) {
        int toppingType = 0;
        int moreToppings = 0;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive)" << std::endl; //loops when type 'olive'
        std::cin >> toppingType;
        if (toppingType == 1 || toppingType == 2) {
            toppingExists = pizza.addToppings(toppingType);
        } else {
            std::cout << "This is not a valid input. Please try again" << std::endl;
        }
        if (toppingExists) {
            std::cout << "Would you like to add another topping? (1 for yes, 0 for no)" << std::endl;
            std::cin >> moreToppings;
            
            if (moreToppings == 1) {
                toppingExists = false; // Continue the loop
            } else {
                std::cout << "No more toppings were added." << std::endl;
                toppingExists = true; // Exit the loop
            }
        }
    }
    std::vector<Topping*> toppings = pizza.getToppings();
    for (std::size_t i = 0; i < toppings.size(); i++) {
        std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
    }
    toppingExists = false;
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive)" << std::endl;
        std::cin >> toppingType;
        toppingExists = pizza.removeToppingFromPizza(toppingType);
        std::cout << "Vector size is " << toppings.size() << std::endl;
        if (toppingExists) {
            std::cout << "Would you like to remove another topping? (1 for yes, 0 for no)" << std::endl;
            std::cin >> moreToppings;
            if (moreToppings == 1) {
                toppingExists = false;
            } else {
                std::cout << "No more toppings were removed." << std::endl;
            }
        }
    }
    std::vector<Topping*> newToppings = pizza.getToppings(); //fix to reallocate properly, also to prevent removing more toppings than can be added
    delete toppings[0];
    toppings = newToppings;

    for (std::size_t i = 0; i < toppings.size(); i++) {
        std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
    }
    return 0;
}