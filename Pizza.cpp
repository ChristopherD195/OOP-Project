#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"
#include "Pepperoni.h"
#include "Chicken.h"
#include "Meat.h"

// Constructor to initialize the Pizza object with default values
Pizza::Pizza() {
    this->radius = 400;  // Default radius of the pizza in pixels or units
    this->crustThickness = 50; // Default crust thickness (to be defined or adjusted)
}

// Getter function to return the radius of the pizza
float Pizza::getRadius() {
    return radius;
}

// Getter function to return the crust thickness of the pizza
float Pizza::getCrustThickness() {
    return crustThickness;
}

// Function to add a topping to the pizza based on the topping type provided
bool Pizza::addToppings(int toppingType) {
    switch (toppingType) {
    case 1: { // Case for pineapple topping
        Topping* pepperoni = new Pepperoni();  // Create a new Pineapple topping object
        this->toppings.push_back(pepperoni);   // Add the topping to the toppings vector
        std::cout << "Topping added successfully" << std::endl;
        break;
    }
    case 2: { // Case for pineapple topping
        Topping* chicken = new Chicken();  // Create a new Pineapple topping object
        this->toppings.push_back(chicken);   // Add the topping to the toppings vector
        std::cout << "Topping added successfully" << std::endl;
        break;
    }
    case 3: { // Case for pineapple topping
        Topping* pineapple = new Pineapple();  // Create a new Pineapple topping object
        this->toppings.push_back(pineapple);   // Add the topping to the toppings vector
        std::cout << "Topping added successfully" << std::endl;
        break;
    }
    case 4: { // Case for olive topping
        Topping* olive = new Olive();  // Create a new Olive topping object
        this->toppings.push_back(olive);  // Add the topping to the toppings vector
        std::cout << "Topping added successfully" << std::endl;
        break;
    }
    default:  // If an invalid topping type is entered
        std::cout << "This topping does not exist. Please try again." << std::endl;
        return false;  // Return false to indicate the addition was unsuccessful
        break;
    }
    return true;  // Return true to indicate the topping was added successfully
}

// Function to remove a topping from the pizza based on the topping type provided
bool Pizza::removeToppingFromPizza(int toppingType) {
    std::string toppingString = "";  // Variable to store the name of the topping to remove
    switch (toppingType) {
    case 1: {
        toppingString = "pepperoni";  // Set the string to "pineapple" if topping type 1 is chosen
        break;
    }
    case 2: {
        toppingString = "chicken";  // Set the string to "olive" if topping type 2 is chosen
        break;
    }
    case 3: {
        toppingString = "pineapple";
        break;
    }
    case 4: {
        toppingString = "olive";
        break;
    }
    default:  // If an invalid topping type is entered
        std::cout << "This topping does not exist. Please try again." << std::endl;
        return false;  // Return false to indicate the removal was unsuccessful
        break;
    }

    int element = -1;  // Variable to store the index of the topping to remove

    // Loop through the toppings vector to find the topping to remove
    for (std::size_t i = 0; i < toppings.size(); i++) {
        std::cout << "Checking element " << i << " of toppings" << std::endl;
        
        // Check if the topping at index i matches the topping to be removed
        if (toppings[i] && toppings[i]->getToppingType() == toppingString) {
            std::cout << "Topping " << i << " is the same" << std::endl;
            element = static_cast<int>(i);  // Store the index of the topping
            break;
        } else {
            std::cout << "Topping " << i << " is not the same" << std::endl;
        }
    }
    
    if (element >= 0) {  // If the topping was found
        toppings.erase(toppings.begin() + element);  // Remove the topping from the vector
        std::cout << "Topping erased" << std::endl;
        return true;  // Return true to indicate the topping was removed successfully
    }
    
    std::cout << "Could not erase this topping" << std::endl;
    return false;  // Return false if the topping was not found or could not be removed
}

// Getter function to return the list of toppings (read-only access)
std::vector<Topping*>& Pizza::getToppings() {
    return this->toppings;  // Return the reference to the toppings vector
}

// Destructor to clean up dynamically allocated memory for toppings
Pizza::~Pizza () {
    // Loop through each topping pointer in the vector
    for (Topping* topping : toppings) {
        delete topping;  // Free each dynamically allocated topping object
    }
    toppings.clear();  // Clear the toppings vector to ensure no dangling pointers
}

// Placeholder for a function to set pizza cutting (if needed in the future)
// void setCutting() {}
