#include "PlayerPizza.h"
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
#include <ctime>

int main() {
    
    int stopGame = 0;
        // Player and customer pizzas
    PlayerPizza pizza;
    CustomerPizza customer;
    std::string gameStateFile = "game_state.txt";  // Game state file
    Efficiency efficiency;// Initialize an efficiency object
    int gameStage = 0;  // Initialize game stage

    // Check if the game state file exists
    std::ifstream file(gameStateFile, std::ios::binary);
    bool fileExists = file.good();
    file.close();  // Close the file

    if (fileExists) {
        std::cout << "A saved game was found. Would you like to load it? (1 for Yes, 0 for No)" << std::endl;
        std::string loadChoice;
        std::cin >> loadChoice;

        if (loadChoice == "1") {
            // Load the game
            gameStage = State::loadGame(pizza, customer, gameStateFile,efficiency);
            if (gameStage == 0) {
                std::cout << "Starting a new round..." << std::endl;
            } else {
                std::cout << "Resuming from where you left off..." << std::endl;
            }
        } else {
            std::cout << "Starting a new game..." << std::endl;
        }
    } else {
        std::cout << "No saved game found. Starting a new game..." << std::endl;
    }

    while(!stopGame) {
    //keep the game running
    srand(time(0));  // Initialize random seed
    

    // Game introduction
    std::cout << "Hello and welcome to the pizza shop! Press enter to continue." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get();  // Pause for player to press enter

    // Game logic based on gameStage
    if (gameStage == 0) {
        std::cout << "In this game, you will receive a customer order, make a pizza, add toppings, bake it, and deliver it." << std::endl;
        std::cout << "The pizza shop has now opened!" << std::endl;

        // Simulate customer entering the shop
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Waiting for a customer to enter the shop..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "A new customer has entered the store!" << std::endl;

        // Option to take the order or quit
        std::cout << "Press 1 to take their order or 'q' to quit and save." << std::endl;
        std::string input;
        while (true) {
            std::cin >> input;
            if (input == "q") {
                State::saveGame(pizza, customer, gameStateFile, 1, efficiency);
                std::cout << "Game saved. Exiting..." << std::endl;
                return 0;
            } else if(input == "1") {
                break;
            } else {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
            }
        }
        
        // Process customer order
        customer.updateToppingOrder();
        const std::vector<int>& customerToppings = customer.getToppingOrder();
        customer.updateOvenDuration();
        customer.updateNumCuts();

        std::cout << "Customer order: " << std::endl;
        std::cout << "Number of pepperoni slices: " << customerToppings[0] << std::endl;
        std::cout << "Number of chicken slices: " << customerToppings[1] << std::endl;
        std::cout << "Number of pineapple slices: " << customerToppings[2] << std::endl;
        std::cout << "Number of olive slices: " << customerToppings[3] << std::endl;

        gameStage = 1;  // Move to the next game stage
    }

    if (gameStage == 1) {
        // Create a new pizza or quit
        std::cout << "Press 1 to create a new pizza or 'q' to quit and save." << std::endl;
        std::string input;
        while (true) {
            std::cin >> input;
            if (input == "q") {
                State::saveGame(pizza, customer, gameStateFile, 1,efficiency);
                std::cout << "Game saved. Exiting..." << std::endl;
                return 0;
            } else if(input == "1") {
                break;
            } else {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
            }
        }
        const std::vector<Topping*>& toppings = pizza.getToppings();
        // Adding toppings loop
        while (pizza.getIsTopped() == 0) {
            int toppingType = 0;
            int moreToppings = 0;

            std::cout << "Please select a topping type:\n";
            std::cout << "Pepperoni: 1\nChicken: 2\nPineapple: 3\nOlive: 4\n";
            std::cout << "Or press 'q' to quit and save." << std::endl;

            while (true) {
                std::cin >> input;
                if (input == "q") {
                    State::saveGame(pizza, customer, gameStateFile, 1,efficiency);
                    std::cout << "Game saved. Exiting..." << std::endl;
                    return 0;
                } else if(input == "1" || input == "2" || input == "3" || input == "4") {
                    break;
                } else {
                    std::cout << "This is not a valid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
                }
            }

            toppingType = std::stoi(input);
            bool pizzaAdded = pizza.addToppings(toppingType);  // Add the selected topping

            // Display all toppings added
            if (!toppings.empty()) {
                for (std::size_t i = 0; i < toppings.size(); i++) {
                    std::cout << "Topping " << i + 1 << " on the pizza is " << toppings[i]->getToppingType() << std::endl;
                }
            } else {
                std::cout << "The pizza has no toppings." << std::endl;
            }
             // Add a new topping
            if (pizzaAdded) {
                std::cout << "Would you like to add another topping? (1 for yes, 0 for no)" << std::endl;
                while (true) {
                    std::cin >> input;
                    if (input == "1" || input == "0") {
                        moreToppings = std::stoi(input);
                        pizza.setIsTopped(!moreToppings);  // Player finishes topping
                        break;
                    } else {
                        std::cout << "This is not a valid input. Please try again." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
                    }
                }
            }
        }

        // Display all toppings added
        if (!toppings.empty()) {
            for (std::size_t i = 0; i < toppings.size(); i++) {
                std::cout << "Topping " << i + 1 << " on the pizza is " << toppings[i]->getToppingType() << std::endl;
            }
        } else {
            std::cout << "The pizza has no toppings." << std::endl;
        }

     // REMOVE TOPPINGS
    int continueToRemoveToppings = 0;
    std::cout << "Press 1 to remove a topping. Press any other integer if you do not wish to remove a topping." << std::endl;
    while (!(std::cin >> continueToRemoveToppings)) {
        std::cout << "This is not a valid input. Please try again.\n";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    if (continueToRemoveToppings == 1) {
        bool toppingExists = false;
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
                    std::cout << "Topping " << i+1 << " is " << toppings[i]->getToppingType() << std::endl;
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
    // Display toppings
    if (!toppings.empty()) {
        for (std::size_t i = 0; i < toppings.size(); i++) {
            std::cout << "Topping " << i + 1 << " on the pizza is " << toppings[i]->getToppingType() << std::endl;
        }
    } else {
        std::cout << "The pizza has no toppings." << std::endl;
    }

    gameStage = 2;  // Move to the next game stage

    //calculate the efficiency of toppings
    efficiency.setToppingsEfficiency(pizza.getToppings(), customer.getToppingOrder());
    std::cout << "Topping efficiency: " << efficiency.getToppingsEfficiency() << std::endl;
    }
    std::string input;
    if (gameStage == 2) {
        // Bake the pizza or quit
        std::cout << "The customer wishes for the pizza to be baked for " << customer.getOvenDuration() << " seconds." << std::endl;
        std::cout << "Press 1 to bake the pizza or 'q' to quit and save." << std::endl;
        while (true) {
            std::cin >> input;

            if (input == "q") {
                State::saveGame(pizza, customer, gameStateFile, 2,efficiency);
                std::cout << "Game saved. Exiting..." << std::endl;
                return 0;
            } else if (input == "1") {
                break;
            } else {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
            }
        }

        pizza.setOvenStartTime();
        std::cout << "Pizza is now in the oven." << std::endl;

        // Option to pause while baking
        std::string input;
        std::cout << "Press 'q' to quit and save during the baking process, or press 1 to continue baking." << std::endl;
            while (true) {
                std::cin >> input;

                if (input == "q") {
                    State::saveGame(pizza, customer, gameStateFile, 2,efficiency);
                    std::cout << "Game saved. Exiting..." << std::endl;
                    return 0;
                } else if (input == "1") {
                    break;
                } else {
                    std::cout << "This is not a valid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
                }
            }
        
        // Take pizza out of the oven
        std::cout << "Press 1 to take the pizza out of the oven." << std::endl;
        std::cin >> input;

        pizza.setOvenDuration();
        pizza.setIsBaked(true);
        std::cout << "Pizza was baked for " << pizza.getOvenDuration() << " seconds." << std::endl;

        gameStage = 3;  // Move to the next game stage
        // Calculate oven baking efficiency
        efficiency.setOvenDurationEfficiency(customer.getOvenDuration(), pizza.getOvenDuration());
        std::cout << "Oven efficiency: " << efficiency.getOvenDurationEfficiency() << std::endl;
    }

    if (gameStage == 3) {
        // Cut the pizza or quit
        std::cout << "The customer wants " << customer.getNumCuts() << " cuts, which makes " << customer.getNumCuts() << " slices." << std::endl;
        std::cout << "Press 1 to cut the pizza or 'q' to quit and save." << std::endl;
        std::string input;
        while (true) {;
            std::cin >> input;
            if (input == "q") {
                State::saveGame(pizza, customer, gameStateFile, 3,efficiency);
                std::cout << "Game saved. Exiting..." << std::endl;
                return 0;
            } else if (input == "1") {
                break;
            } else {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
            }
        }

        int playerPizzaCuts = 0;
        std::cout << "How many cuts do you wish to make: " << std::endl;
        while (true) {
            if (std::cin >> playerPizzaCuts) {
                break;
            } else {
                std::cout << "This is not a valid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //delete unused cin
            }
        }
        pizza.setNumCuts(playerPizzaCuts);

        // Calculate tips and efficiency
        efficiency.setCuttingEfficiency(customer.getNumCuts(), pizza.getNumCuts());
        std::cout << "Cuts efficiency: " << efficiency.getCuttingEfficiency() << std::endl;
        // Interactive feedback with tips, customer reactions
        std::cout << "Customer feedback:" << std::endl;
        pizza.updateTotalTips(customer.getBaseTip(), efficiency.getExtraTip());
        customer.reaction(efficiency);
        std::cout << "The player earned a tip of: $" << pizza.getTotalTips() << std::endl;
    }

    std::cout << "The pizza has now been delivered. Thanks for playing!" << std::endl;

    // Ask if use wishes to continue
    std::cout << "Do you wish to keep playing? Press 1 to continue, press 0 to end." << std::endl;
    int userKeepGame =0;
    std::cin >> userKeepGame;
    
    if (userKeepGame == 1)
    {
       stopGame = 0;
       gameStage = 0;
       pizza.reset(); //set values in PlayerPizza to 0 to replay
    } else if (userKeepGame == 0) {
        stopGame = 1;
    } else{
        std::cout << "Invalid input. Try again." <<std::endl;
    }
    
    }
    std::cout <<"That's the end of the game."<<std::endl;
    std::ofstream fileOut("game_state.txt");// Overwrite the content
    file.close(); // Close immediately to delete content
}