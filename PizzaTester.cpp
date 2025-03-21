/* No testing for abstract class
#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>
#include <limits>

//Tested before Pizza class gets changed into abstract class. Worked properly.
int main() {
    Pizza pizza;    
    //TEST ADD TOPPING
    bool toppingExists = false;
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive):\n"; //loops when type 'olive
        while (!(std::cin >> toppingType)) {
            std::cout << "This is not a valid input. Please try again.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }

        bool pizzaAdded = pizza.addToppings(toppingType);
        
        if (pizzaAdded) {
            std::cout << "Would you like to add another topping? (1 for yes, 0 for no)" << std::endl;
            while (!(std::cin >> moreToppings)) {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            
            if (moreToppings == 1) {
                toppingExists = false; // Continue the loop
            } else {
                std::cout << "No more toppings were added." << std::endl;
                toppingExists = true; // Exit the loop
            }
        }
    }
    const std::vector<Topping*>& toppings = pizza.getToppings(); //read access to the toppings (original vectpr)
    if (toppings.size() > 0) {
        for (std::size_t i = 0; i < toppings.size(); i++) {
            std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
            toppingExists = false;
        }
    } else {
        std::cout << "The pizza has no more toppings" << std::endl;
    }
    

    //TEST REMOVE TOPPING
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        std::cout << "Now we will remove toppings from the pizza" << std::endl;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive)" << std::endl;
        while (!(std::cin >> toppingType)) {
            std::cout << "This is not a valid input. Please try again." << std::endl;
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
        toppingExists = pizza.removeToppingFromPizza(toppingType);

        if (!toppings.empty()) {
            for (std::size_t i = 0; i < toppings.size(); i++) {
                std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
            }
            std::cout << "Would you like to remove a topping? (1 for yes, 0 for no)" << std::endl;
            while (!(std::cin >> moreToppings)) {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            if (moreToppings == 1) {
                toppingExists = false;
            } else {
                std::cout << "No more toppings were removed." << std::endl;
            }
        } else {
            std::cout << "The pizza has no more toppings" << std::endl;
        }
    }
    return 0;
}*/