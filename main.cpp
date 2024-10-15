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
    srand(time(0));  // Seed for random generation
    PlayerPizza pizza;    // Create a new PlayerPizza object
    CustomerPizza customer;  // Create a new CustomerPizza object

    int userChoice = 0;
    std::string gameStateFile = "game_state.dat";  // File to save/load game state

    // Offer the player a choice to start a new game or load a saved game
    std::cout << "Welcome to the Pizza Shop Game! Press 1 to start a new game or 2 to load a saved game." << std::endl;
    while (!(std::cin >> userChoice) || (userChoice != 1 && userChoice != 2)) {
        std::cout << "Invalid input. Please press 1 to start a new game or 2 to load a saved game." << std::endl;
        std::cin.clear();  // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
    }

    // Load the game state if the player chooses to load the game
    if (userChoice == 2) {
        State::loadGame(pizza, customer, gameStateFile);
    }

    // Simulate waiting for a customer
    std::cout << "In this game, you will receive a customer order, make a pizza, add toppings, and bake the pizza." << std::endl;
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

    std::cout << "Customer order:\n";
    std::cout << "Pepperoni: " << customerToppings[0] << "\n";
    std::cout << "Chicken: " << customerToppings[1] << "\n";
    std::cout << "Pineapple: " << customerToppings[2] << "\n";
    std::cout << "Olive: " << customerToppings[3] << "\n";
    std::cout << "Oven time: " << customer.getOvenDuration() << "\n";
    std::cout << "Number of cuts: " << customer.getNumCuts() << "\n";

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
            std::cout << "Would you like to add another topping? (1 for yes, 0 for no, 'q' to quit and save)" << std::endl;
            std::cin >> input;
            if (input == "q") {
                State::saveGame(pizza, customer, gameStateFile);
                std::cout << "Game saved. Exiting..." << std::endl;
                return 0;
            }
            moreToppings = std::stoi(input);
            toppingExists = (moreToppings != 1);
        }
    }

    // Bake the pizza
    std::cout << "Press 1 to bake the pizza or 'q' to quit and save." << std::endl;
    std::cin >> input;
    if (input == "q") {
        State::saveGame(pizza, customer, gameStateFile);
        std::cout << "Game saved. Exiting..." << std::endl;
        return 0;
    }
    pizza.setOvenStartTime();
    std::cout << "Pizza is now in the oven." << std::endl;

    // Finish baking the pizza
    std::cout << "Press 1 to take the pizza out of the oven or 'q' to quit and save." << std::endl;
    std::cin >> input;
    if (input == "q") {
        State::saveGame(pizza, customer, gameStateFile);
        std::cout << "Game saved. Exiting..." << std::endl;
        return 0;
    }
    pizza.setOvenDuration();
    pizza.setIsBaked(true);
    std::cout << "Oven duration: " << pizza.getOvenDuration() << std::endl;
    std::cout << "isBaked status: " << pizza.getIsBaked() << std::endl;

    // Offer to save the game before exiting
    std::cout << "Press 1 to save the game, or any other key to exit without saving." << std::endl;
    std::cin >> input;
    if (input == "1") {
        State::saveGame(pizza, customer, gameStateFile);
    }

    return 0;
}
