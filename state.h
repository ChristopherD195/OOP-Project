
#include <iostream>
#include <fstream>
#include <vector>
#include "PlayerPizza.h"
#include "CustomerPizza.h"
#include "Efficiency.h"

//State class to handle saving and loading player's progress
class State {
public:
    // Save function that writes game data to a file
    static void saveGame(PlayerPizza& pizza, CustomerPizza& customer, std::string GameState,int gameStage) {
        std::ofstream file(GameState, std::ios::out | std::ios::binary);
        if (!file) {
            std::cout << "Error opening file for saving." << std::endl;
            return;
        }

        // Save game stage
        file.write(reinterpret_cast<char*>(&gameStage), sizeof(gameStage));

        // Save Player Pizza state
        bool isBaked = pizza.getIsBaked();
        bool isCut = pizza.getIsCut();
        bool isTopped = pizza.getIsTopped();
        float playerTips = pizza.getTotalTips();
        file.write(reinterpret_cast<char*>(&isTopped), sizeof(isTopped));
        file.write(reinterpret_cast<char*>(&isBaked), sizeof(isBaked));
        file.write(reinterpret_cast<char*>(&isCut), sizeof(isCut));
        file.write(reinterpret_cast<char*>(&playerTips), sizeof(playerTips));

        // Save Customer Pizza state
        int ovenDuration = customer.getOvenDuration();
        int numCuts = customer.getNumCuts();
        std::vector<int> toppingOrder = customer.getToppingOrder();
        size_t toppingOrderSize = toppingOrder.size();
        file.write(reinterpret_cast<char*>(&toppingOrderSize),sizeof(toppingOrderSize));//write the size
        file.write(reinterpret_cast<char*>(toppingOrder.data()),toppingOrderSize*sizeof(int));//write the content
        file.write(reinterpret_cast<char*>(&ovenDuration), sizeof(ovenDuration));
        file.write(reinterpret_cast<char*>(&numCuts), sizeof(numCuts));
        

        file.close();
        std::cout << "Game saved successfully!" << std::endl;
    }

    // Load topping, bake, and cut information by reading game data from a file
    static int loadGame(PlayerPizza& pizza, CustomerPizza& customer, std::string GameState) {
        std::ifstream file(GameState, std::ios::in | std::ios::binary);
        if (!file) {
            std::cout << "Error opening file for loading." << std::endl;
            return-1;
        }

        // Load game stage
        int gameStage;
        file.read(reinterpret_cast<char*>(&gameStage), sizeof(gameStage));

        // Load PlayerPizza state
        bool isBaked;
        bool isCut;
        bool isTopped;
        float playerTips;
        file.read(reinterpret_cast<char*>(&isTopped), sizeof(isTopped));
        file.read(reinterpret_cast<char*>(&isBaked), sizeof(isBaked));
        file.read(reinterpret_cast<char*>(&isCut), sizeof(isCut));
        file.read(reinterpret_cast<char*>(&playerTips), sizeof(playerTips));
        

        // Set the PlayerPizza values after loading
        pizza.setIsBaked(isBaked);
        pizza.setIsCut(isCut);
        pizza.setIsTopped(isTopped);
        pizza.setTotalTips(playerTips);

        // Load Customer Order state
        int ovenDuration;
        int numCuts;
        std::vector<int> toppingOrder;
        size_t toppingOrderSize;
        file.read(reinterpret_cast<char*>(&toppingOrderSize), sizeof(toppingOrderSize));  // Read the size
        toppingOrder.resize(toppingOrderSize);  // Resize the vector to hold the correct number of elements
        file.read(reinterpret_cast<char*>(toppingOrder.data()), toppingOrderSize*sizeof(int));
        file.read(reinterpret_cast<char*>(&ovenDuration), sizeof(ovenDuration));
        file.read(reinterpret_cast<char*>(&numCuts), sizeof(numCuts));
        

        // Set the Customer values after loading
        customer.setOvenDuration(ovenDuration);
        customer.setNumCuts(numCuts);
        customer.setToppingOrder(toppingOrder);

        file.close();
        std::cout << "Game loaded successfully!" << std::endl;

        return gameStage;
    }
};

