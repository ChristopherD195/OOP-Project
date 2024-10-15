#include "Pizza.h"
#include "PlayerPizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"
#include "Pepperoni.h"
#include "Chicken.h"
#include "CustomerPizza.h"
#include "Efficiency.h"
#include "state.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <limits>
#include "PlayerPizza.h"
#include "CustomerPizza.h"
#include "State.h"

int main() {
    srand(time(0));
    int newPizza = 0;
    //Explain the game
    std::cout << "Hello and welcome to the pizza shop!. Press enter to continue.";
    std::cin.get(); //Press enter to continue
    std::cout << "In this game you will receive a customer order, from which you must make a pizza, add toppings, and bake the pizza." << std::endl;
    std::cout << "Press enter to continue.";
    std::cin.get(); //Press enter to continue
    std::cout << "The pizza shop has now opened!" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Waiting for a customer to enter the shop..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "A new customer has entered the store!" << std::endl;

    // Check if the player wants to quit
    std::cout << "Press 1 to take their order or 'q' to quit and save." << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "q") {
        State::saveGame(pizza, customer, gameStateFile);
        std::cout << "Game saved. Exiting..." << std::endl;
        return 0;
    }

    // Take customer order
    customer.updateToppingOrder();
    const std::vector<int>& customerToppings = customer.getToppingOrder();
    customer.updateOvenDuration();
    customer.updateNumCuts();
    int customerNumCuts = customer.getNumCuts();
    std::cout << "Customer order: " << std::endl;
    std::cout << "Number of pepperoni slices: " << customerToppings[0] << std::endl;
    std::cout << "Number of chicken slices: " << customerToppings[1] << std::endl;
    std::cout << "Number of pineapple slices: " << customerToppings[2] << std::endl;
    std::cout << "Number of olive slices: " << customerToppings[3] << std::endl;

    // Check if the player wants to quit before creating the pizza
    std::cout << "Press 1 to create a new Pizza or 'q' to quit and save." << std::endl;
    std::cin >> input;
    if (input == "q") {
        State::saveGame(pizza, customer, gameStateFile);
        std::cout << "Game saved. Exiting..." << std::endl;
        return 0;
    }

    // Start adding toppings to the pizza
    pizza.setIsTopped(true);
    bool toppingExists = false;

    // Add toppings loop
    while (!toppingExists) {
        int toppingType = 0;
        int moreToppings = 0;
        
        std::cout << "Please select a topping type:\n";
        std::cout << "Pepperoni: 1\nChicken: 2\nPineapple: 3\nOlive: 4\n";
        std::cout << "Or press 'q' to quit and save." << std::endl;
        std::cin >> input;
        if (input == "q") {
            State::saveGame(pizza, customer, gameStateFile);
            std::cout << "Game saved. Exiting..." << std::endl;
            return 0;
        }
        toppingType = std::stoi(input);

        bool pizzaAdded = pizza.addToppings(toppingType);

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
    if (toppings.size() > 0) {
        for (std::size_t i = 0; i < toppings.size(); i++) {
            std::cout << "Topping " << i+1 << " on the pizza is " << toppings[i]->getToppingType() << std::endl;
            toppingExists = false;  // Reset toppingExists to false for further actions
        }
    } else {
        std::cout << "The pizza has no toppings" << std::endl;  // If no toppings were added
    }
    
    // REMOVE TOPPINGS
    int continueToRemoveToppings = 0;
    std::cout << "Press 1 to remove a topping. Press any other integer if you do not wish to remove a topping." << std::endl;
    while (!(std::cin >> continueToRemoveToppings)) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    // TEST: REMOVE TOPPING
    if (continueToRemoveToppings == 1) {
        while (toppingExists == false) {
            int toppingType = 0;
            int moreToppings = 0;
            std::cout << "Now we will remove toppings from the pizza" << std::endl;
            std::cout << "Please select a topping type as seen below\n";
            std::cout << "Pepperoni: 1\n";
            std::cout << "Chicken: 2\n";
            std::cout << "Pineapple: 3\n";
            std::cout << "Olive: 4\n";
            
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
    }

    // Place pizza in the oven
    std::cout << "The customer wishes for the pizza to be baked for " << customerOvenTime << " seconds." << std::endl;
    int startBaking = 0;
    std::cout << "Press 1 to bake the pizza." << std::endl;
    while (!(std::cin >> startBaking) || startBaking != 1) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    pizza.setOvenStartTime();
    std::cout << "Pizza is now in the oven." << std::endl;

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
    
    // Cut the pizza
    std::cout << "The customer wishes for the pizza to have " << customerNumCuts << " cuts." << std::endl;
    std::cout << "That is, they want " << customerNumCuts + 1 << " slices." << std::endl;
    int playerPizzaCuts = 0;
    
    std::cout << "How many cuts do you wish to make: " << std::endl;
    while (!(std::cin >> playerPizzaCuts)) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    pizza.setNumCuts(playerPizzaCuts);

    // Return pizza to customer
    int returnPizza = 0;
    std::cout << "Press 1 to pack and return the pizza to the customer." << std::endl;
    while (!(std::cin >> returnPizza) || returnPizza != 1) {
        // Ensure valid input: only '1' is accepted to proceed with giving the pizza back to the customer
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state after invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    //Calculate tips and efficiency
    Efficiency efficiency;
    efficiency.setToppingsEfficiency(toppings, customer.getToppingOrder());
    std::cout << "Topping efficiency: " << efficiency.getToppingsEfficiency() << std::endl;
    efficiency.setOvenDurationEfficiency(pizza.getOvenDuration(), customerOvenTime);
    std::cout << "Baking time efficiency: " << efficiency.getOvenDurationEfficiency() << std::endl;
    efficiency.setCuttingEfficiency(pizza.getNumCuts(), customerNumCuts);
    std::cout << "Cutting efficiency: " << efficiency.getCuttingEfficiency() << std::endl;

    efficiency.setExtraTip();
    std::cout << "Customer feedback:" << std::endl;
    pizza.updateTotalTips(customer.getBaseTip(), efficiency.getExtraTip());
    customer.reaction(efficiency);
    std::cout << "The total tip is $" << pizza.getTotalTips() << std::endl;
    return 0;
}
