#include "Pizza.h"
#include "PlayerPizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>
#include <limits>

int main() {
    int newPizza = 0;
    
    // Prompt user to create a new pizza
    std::cout << "Press 1 to create a new Pizza." << std::endl;
    while (!(std::cin >> newPizza) || newPizza != 1) {
        // Ensure valid input: only '1' is accepted to proceed with pizza creation
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state after invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    PlayerPizza pizza;  // Create a new PlayerPizza object
    bool toppingExists = false;
    
    // Start loop to add toppings to the pizza
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        
        // Ask user to select a topping type (pineapple or olive)
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive):\n";
        while (!(std::cin >> toppingType)) {
            // Ensure valid input
            std::cout << "This is not a valid input. Please try again.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }

        bool pizzaAdded = pizza.addToppings(toppingType);  // Add topping to the pizza based on input
        
        if (pizzaAdded) {
            // Ask user if they want to add more toppings
            std::cout << "Would you like to add another topping? (1 for yes, 0 for no)" << std::endl;
            while (!(std::cin >> moreToppings)) {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            
            // If yes, continue adding toppings
            if (moreToppings == 1) {
                toppingExists = false;
            } else {
                std::cout << "No more toppings were added." << std::endl;
                toppingExists = true;  // Exit the loop if no more toppings are to be added
            }
        }
    }

    // Access toppings vector and display each topping added to the pizza
    const std::vector<Topping*>& toppings = pizza.getToppings(); 
    if (toppings.size() > 0) {
        for (std::size_t i = 0; i < toppings.size(); i++) {
            std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
            toppingExists = false;  // Reset toppingExists to false for further actions
        }
    } else {
        std::cout << "The pizza has no toppings" << std::endl;  // If no toppings were added
    }
    
    // TEST: REMOVE TOPPING
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        std::cout << "Now we will remove toppings from the pizza" << std::endl;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive)" << std::endl;
        
        // Ensure valid input for topping removal
        while (!(std::cin >> toppingType)) {
            std::cout << "This is not a valid input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        toppingExists = pizza.removeToppingFromPizza(toppingType);  // Remove topping from pizza
        
        if (!toppings.empty()) {
            // Display remaining toppings after removal
            for (std::size_t i = 0; i < toppings.size(); i++) {
                std::cout << "Element " << i << " is " << toppings[i]->getToppingType() << std::endl;
            }
            
            // Ask if user wants to remove more toppings
            std::cout << "Would you like to remove a topping? (1 for yes, 0 for no)" << std::endl;
            while (!(std::cin >> moreToppings)) {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (moreToppings == 1) {
                toppingExists = false;  // Continue if user wants to remove more toppings
            } else {
                std::cout << "No more toppings were removed." << std::endl;
            }
        } else {
            std::cout << "The pizza has no more toppings" << std::endl;
        }
    }

    // TEST PlayerPizza functions and display current pizza status
    std::cout << "Default oven duration: " << pizza.getOvenDuration() << std::endl;
    std::cout << "Default isCut: " << pizza.getIsCut() << std::endl;
    std::cout << "Default isBaked: " << pizza.getIsBaked() << std::endl;
    std::cout << "Default isTopped: " << pizza.getIsTopped() << std::endl;
    std::cout << "Default tips: " << pizza.getTips() << std::endl;
    
    // Place pizza in the oven
    int startBaking = 0;
    std::cout << "Press 1 to bake the pizza." << std::endl;
    while (!(std::cin >> startBaking) || startBaking != 1) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    pizza.setOvenStartTime();  // Record the time when pizza is placed in the oven
    std::cout << "Pizza is now in the oven" << std::endl;
    
    // Finish baking the pizza
    int finishBaking = 0;
    std::cout << "Press 1 to take the pizza out of the oven." << std::endl;
    while (!(std::cin >> finishBaking) || finishBaking != 1) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    
    pizza.setOvenDuration();  // Calculate the time the pizza has been in the oven
    pizza.setIsBaked(true);  // Mark the pizza as baked
    std::cout << "Oven duration: " << pizza.getOvenDuration() << std::endl;  // Display oven duration
    std::cout << "isBaked status: " << pizza.getIsBaked() << std::endl;  // Display if pizza is baked
    
    return 0;
}
