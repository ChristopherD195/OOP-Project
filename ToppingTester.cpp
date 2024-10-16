#include <iostream>
#include "Topping.h"
#include "Meat.h"
#include "FruitOrVeg.h"
#include "Pepperoni.h"
#include "Chicken.h"
#include "Olive.h"
#include "Pineapple.h"

void testTopping(Topping* topping) {
    std::cout << "Testing topping: " << topping->getToppingType() << std::endl;
    
    // Test default number of toppings
    std::cout << "Default numTopping: " << topping->getNumTopping() << std::endl;
    
    // Set and test numTopping
    topping->setNumTopping(5);
    std::cout << "Updated numTopping: " << topping->getNumTopping() << std::endl;
    
    // Test numToppingIncrease
    std::cout << "numToppingIncrease: " << topping->getNumToppingIncrease() << std::endl;

    // Call render function
    topping->renderTopping();
    
    std::cout << std::endl; // New line for separation
}

int main() {
    // Edge case: Test with no toppings (default constructor)
    //Topping* emptyTopping = new Topping(); // Should not compile, since Topping is abstract
    
    // Test Meat toppings
    Topping* pepperoni = new Pepperoni();
    testTopping(pepperoni);

    Topping* chicken = new Chicken();
    testTopping(chicken);
    
    // Test FruitOrVeg toppings
    Topping* pineapple = new Pineapple();
    testTopping(pineapple);

    Topping* olive = new Olive();
    testTopping(olive);

    // Edge case: Test setting number of toppings to zero
    pepperoni->setNumTopping(0);
    std::cout << "After setting numTopping to zero: " << pepperoni->getNumTopping() << std::endl;
    
    // Clean up
    delete pepperoni;
    delete chicken;
    delete pineapple;
    delete olive;

    return 0;
}
