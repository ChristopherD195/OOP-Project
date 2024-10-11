#include "Pizza.h"
#include "PlayerPizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"
#include "Pepperoni.h"
#include "Chicken.h"
#include "Customer.h"
#include "Customer_a.h"

#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>

int main() {
    int newPizza = 0;
    //Explaint the game
    std::cout << "Hello and welcome to the pizza shop!. Press enter to continue.";
    std::cin.get(); //Press enter to continue
    std::cout << "In this game you will receive a customer order, from which you must make a pizza, add toppings, and bake the pizza." << std::endl;
    std::cout << "Press enter to continue.";
    std::cin.get(); //Press enter to continue
    std::cout << "The pizza shop has now opened!" << std::endl;

    //Simulate waiting time
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Waiting for customer to enter the shop..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << ". " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << ". " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //Customer enters the store
    std::cout << "A new customer has entered the store!" << std::endl;
    std::cout << "Press 1 to take their order" << std::endl;
    while (!(std::cin >> newPizza) || newPizza != 1) {
        // Ensure valid input: only '1' is accepted to proceed with pizza creation
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state after invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    //Take order
    Customer1 customer;
    customer.setToppingOrder();
    std::vector<int> customerToppings = customer.getToppingOrder();
    customer.setOvenDuration();
    int customerOvenTime = customer.getOvenDuration();
    customer.setNumCuts();
    int customerNumCuts = customer.getNumCuts();
    std::cout << "Customer order: " << std::endl;
    std::cout << "Pepperoni: " << customerToppings[0] << std::endl;
    std::cout << "Chicken: " << customerToppings[1] << std::endl;
    std::cout << "Pineapple " << customerToppings[2] << std::endl;
    std::cout << "Olive " << customerToppings[3] << std::endl;
    std::cout << "Oven time: " << customerOvenTime << std::endl;
    std::cout << "Number of pizza cuts: " << customerNumCuts << std::endl;

    // Prompt user to create a new pizza
    std::cout << "Press 1 to create a new Pizza." << std::endl;
    while (!(std::cin >> newPizza) || newPizza != 1) {
        // Ensure valid input: only '1' is accepted to proceed with pizza creation
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state after invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    PlayerPizza pizza;  // Create a new PlayerPizza object

    int continueToToppings = 0;
    std::cout << "Press 1 to add toppings to the pizza." << std::endl;
    while (!(std::cin >> continueToToppings) || continueToToppings != 1) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    bool toppingExists = false;
    const std::vector<Topping*>& toppings = pizza.getToppings(); 
    // Start loop to add toppings to the pizza
    while (toppingExists == false) {
        int toppingType = 0;
        int moreToppings = 0;
        
        // Ask user to select a topping type (pineapple or olive)
        std::cout << "Please select a topping type as seen below\n";
        std::cout << "Pepperoni: 1\n";
        std::cout << "Chicken: 2\n";
        std::cout << "Pineapple: 3\n";
        std::cout << "Olive: 4\n";
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
