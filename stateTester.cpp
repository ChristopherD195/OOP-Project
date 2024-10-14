#include "state.h"
// This file is a unit tester of stage logging during the game
int main() {
    PlayerPizza pp;
    CustomerPizza cp;

    // Initial customer order
    cp.setBaseTip(2.0);
    cp.setNumCuts(4);
    cp.setOvenDuration(10);
    cp.setToppingOrder({3, 0, 0, 1});

    // Save the game state
    State::saveGame(pp, cp, "GameState.txt");

    PlayerPizza newpp;
    CustomerPizza newcp;

    // Load the game state
    State::loadGame(newpp, newcp, "GameState.txt");

    std::cout << "New Customer Pizza Info:" << std::endl;
    std::cout << "Base Tip: " << newcp.getBaseTip() << std::endl;
    std::cout << "Number of Cuts: " << newcp.getNumCuts() << std::endl;
    std::cout << "Oven Duration: " << newcp.getOvenDuration() << std::endl;

    const auto& toppings = newcp.getToppingOrder();
    std::cout << "Topping Order: ";
    for (int topping : toppings) {
        std::cout << topping << " ";
    }
    std::cout << std::endl;

    return 0;
}
